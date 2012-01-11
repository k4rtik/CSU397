#!/bin/bash

# 4. To print the contents of a file from a given line number to another given line number. Get arguments (file name, first line number, second line number) from command line.

if [ `wc -l $1 | cut -f 1 -d ' '` -lt $3 ] || [ $2 -gt $3 ] 
then
	echo -e "Enter reasonable line numbers!\n\tUsage: $0 <filename> <from line> <to line>"
	exit;
else
	head -n $3 $1 | tail -n `expr $3 - $2 + 1`
fi
