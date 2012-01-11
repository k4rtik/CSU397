#!/bin/bash

# 1. To compare two given numbers and print the largest. Give the numbers as input  from the command line.

if [ $1 -ge $2 ]
then
	echo $1
else echo $2
fi

