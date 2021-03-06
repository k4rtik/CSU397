#!/bin/bash

# 9. Script which accepts a name as argument and then checks whether it exists
#    as a directory. If it doesn’t exit create the directory with the given
#    name or if it exists as an ordinary file, then remove the file and create
#    a directory with the given name.

if [ -d $1 ]
then
	echo "Directory exists."
	exit 0
elif [ -f $1 ]
then
	rm -f $1
fi

mkdir $1
