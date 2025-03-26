for i in $(seq 15 2214);
do
    echo $i
    time ./program < "lab2_primjeri/test$i""/t.ul" > "lab2_primjeri/test$i""/t.iz"
    # rm -rf lab2_primjeri/test$i
done