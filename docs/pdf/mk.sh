#!/bin/bash

gcc --shared -I../ -o document.o ../document.c
gcc --shared -I./ -I../ ./document.o -o pdf.o pdf.c
gcc -I../ -I. ./document.o ./pdf.o -o test test.c
