#!/bin/bash

# To print the lines of a file in reverse

lines=`wc -l $1 | cut -f1 -d' '`

for (( i=$lines; i>0; i-- ))
do
	head -n $i $1 | tail -n 1
done
