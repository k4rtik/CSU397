#!/bin/bash

# 7. To print numbers from 1 to 10, using until construct.

i=1
until [ $i -gt 10 ]
do
	echo $i
	i=`expr $i + 1`
done
