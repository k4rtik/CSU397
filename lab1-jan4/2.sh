#!/bin/bash

# 2. To find whether a given number is Even or Odd.

if [ `expr $1 % 2` -ne 0 ]
then
	echo "Odd"
else echo "Even"
fi

