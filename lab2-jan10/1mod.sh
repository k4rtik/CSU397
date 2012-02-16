#!/bin/bash

# 1. Given a number, check if it is armstrong number or not using function
# construct.

power() {

	result=1
	for (( i=0; i<$2; i++ ))
	do
		result=`expr $result \* $1`
	done
	echo $result
}

armstrong() {
        num=$1
        digits=()
        count=0
        summ="0"
	while [ "$num" -gt 0 ]
        do
		digits[$count]=`expr $num % 10`
                num=`expr $num / 10`
                count=`expr $count + 1`
        done
	for (( i=0; i<$count; i++ ))
	do
		base=${digits[`expr $i`]}
		raised=`power $base $count`
		summ=`expr $summ + $raised`
		echo $i $base $raised $summ
	done
	if [ "$summ" -eq "$1" ]
	then
		echo "$1 is an armstrong number."
	else
		echo "$1 is not an armstrong number."
	fi
}

armstrong $1
