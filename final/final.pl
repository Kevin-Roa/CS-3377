use strict;
use warnings;
use diagnostics;

use 5.32.0;

sub avg {
	my @arr = @{$_[0]};
	my $sum = 0;
	for my $i (@arr) {
		$sum += $i;
	}
	return $sum / 100;
}

sub greaterCount {
	my ($avg, @arr) = @_;
	my $count = 0;
	for my $i (@arr) {
		if ($i > $avg) {
			$count++;
		}
	}
	return $count;
}

sub main {
	my @nums = (1..100);

	for(my $i = 0; $i < 100; $i++) {
		$nums[$i] = int(rand 95) - 11;
	}

	print("@nums\n");

	my $avg = avg(\@nums);
	my $count = greaterCount($avg, @nums);
	print("Average: ", $avg, " Count: ", $count, "\n");

}

main();