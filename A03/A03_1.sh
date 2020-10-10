# Kevin A. Roa
# Edited 9/23/2020
# A shell script to:
#		Copy all files in the current directory to a new sub directory
# 	Then delete the sub directory
#		Then display a message to indicate task completion
#		(This is a useless program)
# Usage (In shell):
#   1. ./A03_1.sh

#!/bin/bash

dir=../subdir

mkdir $dir
cp -R ./* $dir
rm -rf $dir

echo 'Completed task.'
