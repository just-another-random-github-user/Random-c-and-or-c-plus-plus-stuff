#!/usr/bin/env sh
gcc -O0 -s -o sizecheck main.c -DFILE_SIZE=0
if [ "$?" = "1" ]; then return 1; fi
SIZE="$(stat --printf="%s" sizecheck)"
rm sizecheck
gcc -O3 -s -o out main.c "-DFILE_SIZE=$SIZE"
