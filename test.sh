#!/usr/bin/env bash

# set -Ee pipefail

passed_tests=0
failed_tests=0

function cpu_gcd_test() {
    export X1=$((${1}))
    export X2=$((${2}))
    export X3=$((${3}))
    res=$(make | rg "MEM: write \[00000008\]" | sed -e "s/MEM: write \[00000008\]=//" | head -n 1)
    res=$(echo "$res"| bc)
    if [[ "$(echo "$X3 == $res" | bc)" == "1" ]]; then
        passed_tests="$(($passed_tests + 1))"
        # echo "."
        # echo "OK - $X1,$X2 => $X3 == $res"
    else
        failed_tests="$(($failed_tests + 1))"
        echo "FAIL! - $X1,$X2 => $X3 != $res"
    fi
}

echo

cpu_gcd_test 0 0 0
cpu_gcd_test 1 0 1
cpu_gcd_test 0 1 1
cpu_gcd_test 1 1 1
cpu_gcd_test 5 5 5
cpu_gcd_test 5 1 1
cpu_gcd_test 1 5 1
cpu_gcd_test 10 5 5
cpu_gcd_test 21 14 7
cpu_gcd_test 7 3 1
cpu_gcd_test 21 7 7
cpu_gcd_test $((13)) $((13*2)) 13
cpu_gcd_test $((12358*4*7)) $((12358*9)) 12358
cpu_gcd_test 60480 5600 1120

# import math
# import random
# for i in range(100):
#     a = random.randint(2, 1000000)
#     b = random.randint(2, 1000000)
#     c = math.gcd(a, b)
#     print(f"cpu_gcd_test {a} {b} {c}")

if [[ "${1}" == "-l" ]]; then
    cpu_gcd_test 788827 658522 1
    cpu_gcd_test 720635 290528 1
    cpu_gcd_test 682221 68407 1
    cpu_gcd_test 392747 989546 1
    cpu_gcd_test 712413 49084 1
    cpu_gcd_test 285032 772044 4
    cpu_gcd_test 814515 528635 5
    cpu_gcd_test 776180 678037 1
    cpu_gcd_test 515901 742296 3
    cpu_gcd_test 466376 612760 8
    cpu_gcd_test 506205 828861 3
    cpu_gcd_test 857938 945886 2
    cpu_gcd_test 445463 974749 1
    cpu_gcd_test 2008 16032 8
    cpu_gcd_test 687568 725584 16
    cpu_gcd_test 51312 286415 1
    cpu_gcd_test 614284 115763 1
    cpu_gcd_test 372568 593359 1
    cpu_gcd_test 20477 45322 1
    cpu_gcd_test 71142 291833 1
    cpu_gcd_test 367755 772828 1
    cpu_gcd_test 770846 386243 1
    cpu_gcd_test 948210 15729 3
    cpu_gcd_test 998784 142642 2
    cpu_gcd_test 14528 831732 4
    cpu_gcd_test 234769 975576 1
    cpu_gcd_test 158096 907952 16
    cpu_gcd_test 760486 982990 2
    cpu_gcd_test 308752 962866 2
    cpu_gcd_test 178275 969960 15
    cpu_gcd_test 20532 422338 2
    cpu_gcd_test 704177 86732 1
    cpu_gcd_test 428814 268901 1
    cpu_gcd_test 608741 748195 7
    cpu_gcd_test 302212 307316 4
    cpu_gcd_test 958093 822819 1
    cpu_gcd_test 542265 766121 1
    cpu_gcd_test 464255 858662 1
    cpu_gcd_test 653953 616440 1
    cpu_gcd_test 63856 345605 13
    cpu_gcd_test 80654 551148 2
    cpu_gcd_test 254906 7867 1
    cpu_gcd_test 478403 320004 1
    cpu_gcd_test 227142 597489 3
    cpu_gcd_test 372304 490210 2
    cpu_gcd_test 691218 26579 1
    cpu_gcd_test 426937 946548 1
    cpu_gcd_test 558632 430958 2
    cpu_gcd_test 95057 441499 1
    cpu_gcd_test 818991 476150 1
    cpu_gcd_test 735715 36848 1
    cpu_gcd_test 301167 101723 1
    cpu_gcd_test 184286 588258 2
    cpu_gcd_test 954523 154628 1
    cpu_gcd_test 148010 578608 2
    cpu_gcd_test 753272 499751 1
    cpu_gcd_test 500393 977485 1
    cpu_gcd_test 581010 362814 6
    cpu_gcd_test 104390 609089 13
    cpu_gcd_test 964381 877276 1
    cpu_gcd_test 910881 921744 9
    cpu_gcd_test 176392 19424 8
    cpu_gcd_test 890704 759675 1
    cpu_gcd_test 693278 871212 2
    cpu_gcd_test 197057 878594 1
    cpu_gcd_test 340485 85707 3
    cpu_gcd_test 630946 986623 1
    cpu_gcd_test 631455 402381 3
    cpu_gcd_test 182499 664700 1
    cpu_gcd_test 929256 193526 2
    cpu_gcd_test 145406 369885 1
    cpu_gcd_test 586925 281212 1
    cpu_gcd_test 737135 442529 1
    cpu_gcd_test 10459 102869 1
    cpu_gcd_test 75094 202914 2
    cpu_gcd_test 274348 588745 1
    cpu_gcd_test 946002 797437 1
    cpu_gcd_test 989687 212473 1
    cpu_gcd_test 706266 901692 594
    cpu_gcd_test 444733 632942 1
    cpu_gcd_test 524602 60474 2
    cpu_gcd_test 513543 639014 1
    cpu_gcd_test 871302 978127 1
    cpu_gcd_test 855516 964086 6
    cpu_gcd_test 647732 912032 4
    cpu_gcd_test 788278 271101 1
    cpu_gcd_test 849677 426310 1
    cpu_gcd_test 218936 716183 1
    cpu_gcd_test 391968 157806 18
    cpu_gcd_test 895975 533736 1
    cpu_gcd_test 510517 386334 1
    cpu_gcd_test 938369 194078 1
    cpu_gcd_test 892463 141280 1
    cpu_gcd_test 206483 333992 1
    cpu_gcd_test 879580 77725 5
    cpu_gcd_test 203005 224643 1
    cpu_gcd_test 955768 513833 1
    cpu_gcd_test 952438 488843 1
    cpu_gcd_test 802431 363265 7
    cpu_gcd_test 594328 300588 4
fi

if [[ "$failed_tests" == "0" ]]; then
    echo "ALL TESTS PASSED ($passed_tests)"
else
    echo
    echo "=============================================="
    echo
    echo "  PASSED: $passed_tests"
    echo "  FAILED: $failed_tests"
    echo
    echo "=============================================="
fi