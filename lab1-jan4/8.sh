#!/bin/bash

# 8. Move all hidden files from a given directory to a newly created directory.

# Usage: ./8.sh <dir> <new dir name>

mkdir $2
mv $1/.[!.]* $2
