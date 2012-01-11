#!/bin/bash

# 6. To implement following using select construct:
#	a. create a file (using touch)
#	b. rename a file
#	c. delete a file
#	d. copy file
# The script should be menu driven. 

while :
do
	# show menu
	#clear
	echo "---------------------------------"
	echo "	M A I N - M E N U"
	echo "---------------------------------"
	echo "1. Create file"
	echo "2. Rename file"
	echo "3. Delete file"
	echo "4. Copy file"
	echo "5. Exit"
	echo "---------------------------------"
	read -r -p "Enter your choice [1-5] : " c
	# take action
	case $c in
		1) read -p "Enter file name: " file
			touch $file;;
		2) read -p "Enter old name and new name: " old new
			mv $old $new;;
		3) read -p "Enter file name to be deleted: " dfile
			rm $dfile;;
		4) read -p "Enter source and target file names: " src target
			cp $src $target;;
		5) break;;
		*) echo "Select between 1 to 5 only"
	esac
done
