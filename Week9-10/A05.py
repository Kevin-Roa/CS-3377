# Kevin A. Roa
# Edited 10/25/2020
# A python program to:
#		Play a number guessing game
#		Player must repeatedly guess a number -100 to 100 until they get it right
#		Game tells player whether guess was high/low
#		Score output into a report file
# Extra additions:
#		Rules page
#		Input error handling
# Usage (In shell):
#   1. python3 guessingGame.py

import random

# Return a random number within a given range
def getRandomNum(min, max):
	return random.randint(min, max)

# Print rules for game
def printRules(maxGuesses):
	print("~~~~~~~~~~~~~~~~~~~~~~ Rules ~~~~~~~~~~~~~~~~~~~~~~~~\n")
	print("* The player must guess a random number -100 to 100.")
	print("* The player has a maximum of", maxGuesses, "guesses.")
	print("* Every round a tip is given to the player to narrow")
	print("  down the possible answers.\n")
	print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")

# Runs once win condition is met
def onWin(attempts):
	print("You Win!")
	print("You took a total of", attempts, "attemps.")

	# Get name of player
	name = input("\nEnter your name: ")

	# Add player to report file
	file = open("report.txt", "a+")
	file.write(name + " took " + str(attempts) + " attempts.\n")
	file.close()

	print("Score saved to file.")
	exit(1)

#Runs once loss condition is met
def onLoss():
	print("You Lose!")
	print("You took too many attemps.")
	exit(1)

def main():
	# Initialize variables to default values
	num = getRandomNum(-100, 100)
	guess = None
	attempts = 0
	maxGuesses = 7

	printRules(maxGuesses)

	# Runs while player has not guessed the correct number
	while (guess != num):
		# Test if player still has available attempts
		if (attempts < maxGuesses):
			# Catch error if player doesnt enter a valid number
			try:
				# Get number from player
				guess = int(input("Enter a number: "))

				# Error when number not within range
				if (guess < -100 or guess > 100):
					raise ValueError
				
				# Increment attempts if player entered valid number
				attempts += 1
			# Print error on invalid input, ask for new input
			except ValueError:
				print("\nERROR: Please enter a number in the range -100 to 100.\n")
				continue

			# Print whether guess was too high/low/correct
			if (guess < num):
				print("Your guess was too low.\n")
			elif (guess > num):
				print("Your guess was too high.\n")
			else:
				print("You guessed correctly.\n")
				onWin(attempts)
		# End game if no more attempts left
		else:
			onLoss()

	exit(1)

if __name__ == "__main__":
	main()
