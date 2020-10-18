# Kevin A. Roa
# Edited 10/17/2020
# A python script to read a file and print the # of words and sentences.
# Extra additions:
#		File error handling
#		Character count
#		Command line args
# Usage (In shell):
#   1. python3 DB05.py
#		2. python3 DB05.py -h (list of command line args)

import sys
import getopt

def usage():
	print('------------------------------------ DB05.py ------------------------------------')
	print('A program to print the character, word, and sentence count of a file.\n')
	print('ARGUMENTS')
	print('-i | --inputFile <inputFile> : Pass the file to be read instead of prompting you.')
	print('-v | --verbose               : Print in a verbose manner.')
	print('-h | --help                  : Show help page.')
	print('---------------------------------------------------------------------------------')
	exit()

def main(argv):
	# Parse command line options
	try:
		opts, args = getopt.getopt(argv,"hi:v",["help", "inputFile=", "verbose"])
	except getopt.GetoptError as err:
		print(str(err))
		sys.exit(2)
	
	inputFile = None
	verbose = False

	# Set values from given command line options
	for opt, arg in opts:
		if opt in ("-i", "--inputFile"):
			inputFile = arg
		elif opt in ("-v", "--verbose"):
			verbose = True
		elif opt in ('-h', '--help'):
			usage()

	# If no argument was passed then ask user for input
	if (inputFile == None):
		#	Get file name from user
		inputFile = input("Enter a file name: ")

	# Initialize counters
	charCount = wordCount = sentenceCount = 0

	# Catch error if invalid file name
	try:
		# Open file
		with open(inputFile, 'r') as file:
			# Read file
			contents = file.read()
			# Count every occurance of .?! and sum them up
			sentenceCount = sum([contents.count(x) for x in ['.', '?', '!']])
			# Split file on every word and get the count
			wordCount = len(contents.split())
			# Split file on every character and get the count
			charCount = len(list(contents))
	except FileNotFoundError as err:
		# Print error on invalid file name and exit program
		sys.exit(err)

	if (verbose):
		# Print the word and sentence count in a verbose sentence
		print(inputFile, 'has', sentenceCount,'sentences containing a total of', wordCount, 'words and', charCount, 'characters.')
	else:
		# Print the word and sentence count
		print('Sentences:  ', sentenceCount, '\nWords:      ', wordCount, '\nCharacters: ', charCount)

if __name__ == "__main__":
  main(sys.argv[1:])
