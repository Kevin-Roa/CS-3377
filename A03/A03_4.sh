# Kevin A. Roa
# Edited 9/23/2020
# A shell script to count files in a given directory
# Assignment specified to:
# 	Use a for loop construct
#		Prompt the user for a directory
# Usage (In shell):
#   1. ./A03_4.sh

#!/bin/bash

# Prompt for input directory
printf "Enter a directory: "
read dir

# Remove extra / if input included it at end
dir=`echo "$dir" | sed 's/\/$//'`

# Loop through files in directory
count=0
for file in $dir/*;do
	((count++))
	echo $file
done

# Display file count
if [ $count -eq 1 ];then
	echo "$count File."
else
	echo "$count Files."
fi