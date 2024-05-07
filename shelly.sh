#!bin/sh

fun() {

for ((i = $n ; i > 0 ; i--)); do

ans=$(( $i*$ans))

done

echo "Factorial = $ans"

}



echo "Factorial"

ans=1

read -p "Enter Number = " n

#for i in { $n..1 } ; do

fun

