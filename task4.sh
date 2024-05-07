#!/bin/bash

#input
read -p "Enter a number = " n

cntr=1

while [ $cntr -le 10 ]; do
	
	ans=$(( $cntr * $n ))
	echo "$n X $cntr = $ans"
	((cntr++))
	
	done


