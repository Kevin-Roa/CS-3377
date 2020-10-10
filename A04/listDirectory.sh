# Kevin A. Roa
# Edited 9/30/2020
# A shell script to:
#		Display names of directory files in the working directory
#		Don't display any other file type
# Usage (In shell):
#   1. ./listDirectory.sh

#!/bin/bash

# Loop through files in directory
for file in ./*;do
	# Test if the file is a directory type file
	if [ -d $file ]; then
		# Print the file name
		echo $file
	fi
done
