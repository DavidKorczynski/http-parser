#!/bin/bash
$CC $CFLAGS -c ./http_parser/http_parser.c
llvm-ar rcs libfuzz.a *.o


$CC $CFLAGS $LIB_FUZZING_ENGINE $SRC/fuzzer.c -Wl,--whole-archive $SRC/http-parser/libfuzz.a -Wl,--allow-multiple-definition -I$SRC/http-parser/http_parser  -o $OUT/fuzzer
