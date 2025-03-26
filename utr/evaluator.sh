#!/bin/bash

echo "broj labosa: "
read n_lab

echo "kolicina testnih primjera: "
read n_primjera

echo "naziv ulaznih datoteka"
read in_f

echo "naziv izlaznih datoteka"
read out_f

for i in $(echo $n_primjera | python brojac.py);
do
    echo "--------test primjer $i""--------"
    ./program < "lab$n_lab""_primjeri/test$i/$in_f" > "rezultati/output$i"
    diff -s "rezultati/output$i" "lab$n_lab""_primjeri/test$i/$out_f"
done