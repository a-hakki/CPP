#!/bin/zsh
for i in {0..9}; do
    for j in {0..2}; do
        touch "cpp0$i/ex0$j/Makefile"
    done
done

