# Kevin A. Roa
# Edited 10/9/2020
# A shell script to:
#		Play a number guessing game
#		Player must repeatedly guess a number until they get it right
#		Game tells player whether guess was high/low
#		Score output into a highscore file
#		At the end, display top 3 scores from highscores file
#		Extras:
#			Added option to play again
#			Added ability to quit in the middle of playing
#			Added exit message
#			Added input validity checking
#			Utilized functions to increase readability and code reuse
# Usage (In shell):
#   1. ./A04.sh

#!/bin/bash

#	Runs when player guesses the correct number
function onWin {
	#	Displays win prompt and score
	echo "\nYou win!"
	echo "Score: $score"

	saveScore
	displayTopScores
	playAgain
}

#	Save the player's score to a file
function saveScore {
	# Prompt for name
	printf '\nEnter name: '
	read name

	#	Save score + name to highscores file
	echo "$score $name" >> ./highscores
}

# Display the top 3 scores in the highscore file
function displayTopScores {
	echo "\nTop 3 Scores:"
	grep "" ./highscores | sort -n | head -3
	echo ''
}

# Prompt the player if they want to play again
function playAgain {
	while true; do
    read -p "Would you like to play again? " yn
    case $yn in
			# Yes resets the game
			[Yy]* ) resetGame; break;;
			# No ends the game
			[Nn]* ) endGame;;
			# Tell user to enter valid input
			* ) echo "Please answer yes or no.";;
    esac
	done
	echo ''
}

# Resets all necessary values to their defaults
# Generates a new random number
function resetGame {
	let guess=-1
	let score=0
	let num=$(($RANDOM % 129))
}

#	Displays closing message then exits script
function endGame {
	echo "\nThank you for playing."
	exit
}

function runGame {
	resetGame

	echo "Type 'q' at any time to quit the game."

	# Loops until the player guesses the correct number
	# or until 'q' is entered
	while [ $guess -ne $num ];do
		# Prompt to enter number
		printf 'Enter a number: '
		read guess
		# Increment score after guess
		let score++

		#	Test for valid numerical input
		if [[ $guess =~ ^[0-9]+$ ]];then
			#	Test if guess was too high
			if [ $guess -gt $num ];then
				echo 'Your guess was too high.'
			#	Test if guess was too low
			elif [ $guess -lt $num ];then
				echo 'Your guess was too low.'
			#	If guess was correct
			else
				onWin
			fi
		#	If invalid input
		else
			# If input was q then end the game
			if [ $guess == 'q' ];then
				endGame
			fi
			# Otherwise, display an error
			echo 'Please enter a valid number'
			let score--
			let guess=-1
		fi
	done
}

runGame
