#!/bin/bash

# 10. To traverse a directory tree in breadth-first order. ( Breadth-first
#     searches explore all the nodes at a given level before descending lower
#     in the tree.) The input given is a directory name.

d=0
while output=`find $1 -mindepth $d -maxdepth $d` && [[ -n $output ]]
do
	find $1 -mindepth $d -maxdepth $d	
	((d++))
done
