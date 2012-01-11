#!/bin/bash

# 4. To implement a calculator with minimum functionalities(add , sub, mul, div)
# using function & case utility . The script should be menu driven.

add() {
	echo `expr $1 + $2`
}

sub() {
	echo `expr $1 - $2`
}

mul() {
	echo `expr $1 \* $2`
}

div() {
	echo `expr $1 / $2`
}

while :
do
	# show menu
	#clear
	echo "---------------------------------"
	echo "	M A I N - M E N U"
	echo "---------------------------------"
	echo "1. Addition"
	echo "2. Subtraction"
	echo "3. Multiplication"
	echo "4. Division"
	echo "5. Exit"
	echo "---------------------------------"
	read -r -p "Enter your choice [1-5] : " c
	# take action
	case $c in
		1) add $1 $2;;
		2) sub $1 $2;;
		3) mul $1 $2;;
		4) div $1 $2;;
		5) break;;
		*) echo "Select between 1 to 5 only"
	esac
done
