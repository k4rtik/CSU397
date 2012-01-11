#!/bin/bash

# 1. Read 3 numbers and find the largest among them.

read a
read b
read c

if [ $a -ge $b ]
then
	if [ $a -ge $c ]
	then echo "Largest is:" $a
	else echo "Largest is:" $c
	fi
elif [ $b -ge $c ]
then echo "Largest is:" $b
else echo "Largest is:" $c
fi
	
 
