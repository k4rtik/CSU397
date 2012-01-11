#!/bin/bash

# 2. Script which will take backup of all files changed in last day from the given directory.

mkdir -p .backup
find "$1" -mtime 1 -exec cp {} .backup \;
