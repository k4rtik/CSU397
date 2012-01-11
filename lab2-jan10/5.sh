#!/bin/bash

# 5. To read two words and a file name from command line and replace the 
# occurrences of first word with the second word.

read word
read wordd
read file
sed -i s/$word/$wordd/g $file
