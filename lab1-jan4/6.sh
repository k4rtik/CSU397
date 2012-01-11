#!/bin/bash

# 6. To read a directory name as a command line argument and delete all files in that directory whose size is 0 bytes.

find $1 -size 0c -exec rm -i {} \;
