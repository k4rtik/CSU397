#!/bin/bash

# 1. To print month name if month number is given.

months=(January February March April May June July August September October November December)
if [ $1 -gt 12 ] || [ $1 -lt 1 ]
then
	echo "Error! Input correct month number."
	exit
else
	echo ${months[`expr $1-1`]}
fi
