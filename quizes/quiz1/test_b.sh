#!/bin/sh

TEST_DIR=/home/jworkman/Quiz1
EXEC_NAME=a.out

for base in `ls $TEST_DIR/*.inb | sed -e sX.*/XX | sed -e s/\\.inb//`; do
    echo Evaluating test case $base...
    cp -f $TEST_DIR/$base.inb $TEST_DIR/$base.outb .
    ./$EXEC_NAME < $TEST_DIR/$base.inb > my_$base.outb
    diff -b $TEST_DIR/$base.outb my_$base.outb
done
