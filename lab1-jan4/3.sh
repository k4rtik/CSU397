#!/bin/bash

# 3. To check whether the two file contents are same or not. Given two file names as arguments. 

cmp $1 $2 &> /dev/null
if [ $? -ne 0 ]

then
	echo "Different files."
else echo "Same files."
fi

