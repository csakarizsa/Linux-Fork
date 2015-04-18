#!/bin/bash
echo "Hello a 'run.sh'-ból."
echo "Paraméterek: "$*
gcc main.c -o mainpr
./mainpr $* > log.txt