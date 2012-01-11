#!/bin/bash

# 5. To generate all combinations of 1,2 and 3 using for loops.

# Shortcut: echo {1..3}{1..3{1..3}

for (( i=1; i<4; i++ ))
do
	for (( j=1; j<4; j++ ))
	do
		for (( k=1; k<4; k++ ))
		do
			if [ $i -ne $j ] && [ $i -ne $k ] && [ $j -ne $k ]
			then echo $i$j$k
			fi
		done
	done
done  
