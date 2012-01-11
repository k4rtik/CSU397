#!/bin/bash

# 2. To find the factorial of a number using recursive function call.

factorial() {
	if [ "$1" -gt 1 ]
	then
		dec=`expr $1 - 1`
		f=`factorial $dec`
		result=`expr $1 \* $f`
		echo $result
	else
		echo 1
	fi
}

factorial $1
