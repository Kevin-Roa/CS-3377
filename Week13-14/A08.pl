use strict;
use warnings;
use diagnostics;

use 5.32.0;

sub onWin {
	say "You win!\n";

	# Get name form user
	say "Please enter your name.";
	my $name = <STDIN>;
	chomp($name);

	# Set score to passed parameter
	my $score = $_[0];

	# Append score to file
	open my $fh, '>>', "scores.txt"
		or die "cant open file: $_";
	print $fh "$name $score\n";
	close $fh or die "couldnt close file: $_";
	say "\nScore saved to file.";

	exit;
}

sub main {
	# Set default values
	my ($maxGuesses, $numGuesses, $guess) = (7, 1, 0);

	# Generate random number 100-200
	my $secret = int(rand 101) + 100;

	say "Guess the secret number in less than $maxGuesses guesses.";

	# Repeatedly ask for guess until out of guesses
	while ($numGuesses <= $maxGuesses) {
		say "Guess a number from 100 to 200.";
		$guess = <STDIN>;

		if ($guess < $secret) {
			say "Low guess.\n";
		}
		elsif ($guess > $secret) {
			say "High guess.\n";
		}
		elsif ($guess == $secret) {
			onWin($numGuesses);
		}

		$numGuesses++;
	}
	say "You lose.\nYou took too many attemps.";
	exit;
}

main();