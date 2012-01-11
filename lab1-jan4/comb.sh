#!/bin/bash

# 5. To generate all combinations of 1,2 and 3 using for loops.

# Shortcut: echo {1..3}{1..3{1..3}

perm() {
  number="$1"
  out="$2"
  [[ "$number" == "" ]] && echo "$out" && return
  for (( i=0; i<${#number}; i++ )) ; do
    ( perm "${number:0:i}${number:i+1}" "$out${number:i:1}" )
    done
  }
perm "$1"

