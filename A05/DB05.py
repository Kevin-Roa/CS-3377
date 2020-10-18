# Kevin A. Roa
# Edited 10/17/2020
# A python script to read a file and print the # of words and sentences.
# Usage (In shell):
#   1. python3 DB05.py

import sys

def main():
	#	Get file name from user
	fileName = input("Enter a file name: ")

	# Initialize counters
	wordCount = sentenceCount = 0

	# Catch error if invalid file name
	try:
		# Open file
		with open(fileName, 'r') as file:
			# Read file
			contents = file.read()
			# Split file on every word and get the count
			wordCount += len(contents.split())
			# Count every occurance of .?! and sum them up
			sentenceCount += sum([contents.count(x) for x in ['.', '?', '!']])
	except FileNotFoundError as err:
		# Print error on invalid file name and exit program
		sys.exit(err)

	# Print the word and sentence count
	print(fileName, 'has', wordCount,'words and', sentenceCount, 'sentences.')

main()