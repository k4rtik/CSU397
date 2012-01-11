#!/bin/bash

# 5. To generate all combinations of 1,2 and 3 using for loops.

# Shortcut: echo {1..3}{1..3{1..3}

for i in {1..3}{1..3}{1..3}
do
	echo $i
done
