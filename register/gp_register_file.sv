module GPRegisterFile(
    input Clock clk,
    input RegId read_idx_1,
    input RegId read_idx_2,
    input RegId write_idx,
    input Data write_data,
    input Bool write_enable,
    output Data read_data_1_out,
    output Data read_data_2_out
);
    DataReg gp[31:0];

    assign read_data_1_out = read_gp_with_fwd(read_idx_1);
    assign read_data_2_out = read_gp_with_fwd(read_idx_2);

    always @ (posedge clk) begin
        if (write_enable) begin
            if (write_idx != 0) gp[write_idx] <= write_data;
            // $display("REG: r1=%h r2=%h w[%d]=%h", gp[1], gp[2], write_idx, write_data);
        end
    end

    function Data read_gp_with_fwd(
        input RegId read_idx
    );
        if (read_idx == 0)
            read_gp_with_fwd = 'b0;
        else if (write_enable && read_idx == write_idx)
            read_gp_with_fwd = write_data;
        else
            read_gp_with_fwd = gp[read_idx];
    endfunction
endmodule