#!/bin/bash

# 3. To create your own customized shell. After executing the script you will be
# ending up with a prompt with your name and you will be able to execute all
# scripts (questions given for lab assignmnet 1 and 2)with short commands.

export PATH=$PATH:`pwd`/../lab1-jan4
echo $PATH
while :
do
	echo -ne "kartik > "
	read comm
	$comm
done
