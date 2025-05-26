#!/bin/bash

echo "broj labosa: "
read n_lab

echo "kolicina testnih primjera: "
read n_primjera

echo "naziv ulaznih datoteka"
read in_f

echo "naziv izlaznih datoteka"
read out_f

rm -rf rezultati || echo bla > /dev/null
mkdir rezultati

for i in $(seq 1 $n_primjera);
do
    echo "--------test primjer $i""--------"
    ./program < "lab$n_lab""_primjeri/test$i/$in_f" > "rezultati/output$i"
    diff -s "rezultati/output$i" "lab$n_lab""_primjeri/test$i/$out_f" >> "rezultati/output$i"
done

python evaluator_p2.py