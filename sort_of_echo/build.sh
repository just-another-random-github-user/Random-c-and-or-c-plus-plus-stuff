#!/usr/bin/env sh
gcc -O0 -s -o ./sizecheck ./main.c
SIZE="$(stat --printf="%s" ./sizecheck)"
rm ./sizecheck
gcc -O3 -s -o ./out ./main.c "-DFILE_SIZE=$SIZE"
