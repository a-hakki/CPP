#!/bin/zsh
for i in {0..9}; do
    mkdir -p "cpp0$i"
    for j in {0..2}; do
        mkdir -p "cpp0$i/ex0$j"
    done
done

