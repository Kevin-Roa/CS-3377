#!/bin/bash

# for i in {0..99}; do
# 	make clean
# done

printf 'Enter a file or directory: '
read dir

if [ -d "$dir" ]; then
	echo 'Yes'
elif [ -f "$dir" ]; then
	echo 'Yes'
else
	echo 'No'
fi

