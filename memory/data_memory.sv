module DataMemory(
    input Clock clk,
    input Addr idx,
    input Data write_data,
    input Bool write_enable,
    output Data read_data_out
);
    DataReg mem[128:0];
    assign read_data_out = mem[idx[9:2]];

    initial begin
        mem[0] = `X1;
        mem[1] = `X2;
    end

    always @ (posedge clk) begin
        if (write_enable == 1) begin
            mem[idx[9:2]] <= write_data;
            $display("MEM: write [%h]=%h", idx, write_data);
         end
    end
endmodule