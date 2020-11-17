use strict;
use warnings;
use diagnostics;

use feature 'say';
use feature "switch";

use 5.18.4;

# simple hello world
# Double quote lets escape characters to have \n
print "Hello World\n";

# declare variables with my
# Single quotes dont escape characters
my $name = 'Kevin';
# declare and set multiple variables on same line
my ($age, $birthday) = (19, 'february');
# double quotes let you use variables
# escape quote to see quote in string
my $info = "\"$name\" is $age years old.\n";
# alternative so you dont need to escape quotes
$info = qq{"$name" is $age years old.\n};
print $info;

# declare multi line string variable
# END is set to be the ending of the string
my $long_string = <<"END";
This string goes on 
for multiple lines
wow
END
# simliar to print but puts a \n at the end
say $long_string;

# trust up to 16 digits of precision
my $my_int = 1234;
# print a number
# basically the same as c
# %c character
# %s string
# %d decimal
# %u unsigned int
# %f float (dec)
# %e float (scientific)
printf("%u\n", $my_int);
# trust up to 16 digits of precision
my $my_float = 100.10000001;
printf("%f, %e\n", $my_float, $my_float);

# swap values without needing a temp variable
my ($first, $second) = (1, 2);
($first, $second) = ($second, $first);

say "$first, $second";

# math functions
say "addition ", 2+1;
say "subtraction ", 2-1;
say "multiplication ", 2*1;
say "division ", 2/1;
say "remainder ", 2%1;
say "power ", 2**1;
say "sqrt ", sqrt 16;

# math conversions
say "exp ", exp 1; # e^x
say "log ", log 2; # ln x
say "hex ", hex 10;# convert from hex to dec
say "oct ", oct 10; # convert from octal to dec
say "int ", int 1.4; # convert to int, truncate decimal

say "random ", int(rand 11); # int 0-10

#short hand operators
my $num += 1;
$num -= 1;
$num *= 1;
$num /= 1;

# action after line complete
# ex if used in print, will print old value then increment/decriment value
$num++;
$num--;
# action before line complete
# ex if used in print, will increment/decriment value then print new value
++$num;
--$num;
# strings can also be incremented

# conditional logic
# use in conditional statements
# number operators
# == != < > <= >=
# ! && ||
# string operators
# eq ne lt le gt ge

# false in perl
# undef 0 0.0 "" "0"

# declare boolean
my ($condition, $val) = (1, 10); # anything != 0 is true
# if elsif else statement
if ($val <= 5) {
}
elsif ($condition) {
}
else {
}
# opposite of if
unless ($condition) {
}
# ternary
say ($val == 10 ? "when true" : "when false");
# switch statement
given($val) {
	when (5) {
		continue; # continue to check next when
	}
	when (10) {
	}
	default {
	}
}

#loops
for(my $i = 0; $i < 10; $i++) {
}
my $i = 0;
while($i < 10) {
	$i++;
	# skip back to beginning of loop
	next;
	# break out of program
	last;
}
$i = 0;


#keyboard input
my $input_val = <STDIN>;

# string functions
# get length of string
say length $input_val;
# get first index of value in string
# starts at 0
say index $input_val, " ";
# get last index of value in string
say rindex $input_val, " ";
# concatination
say $input_val . ' concat.';
# substring at index 2-6
say substr $input_val, 2, 6;
# delete and return last char in string
my $test = 'example';
say chop $test;
# delete new lines
$test = "example\n";
say chomp $test;
# uppercase/lowercase letters in string
say uc 'text';
say ucfirst 'text';
say lc 'TEXT';
say lcfirst 'TEXT';
# replace all occurrances of first section with second section
# g at end is for all occurrances
# i at end to ignore case
my $testvar = "this is a string. find this section.";
$testvar =~ s/find this/replace with this/g;
say $testvar;
# repeat string
say 'text ' x 2;

# arrays
# define array
# values can be mixed types
my @array = (1,2,3);
# use range of values
@array = (1 .. 5);
# do something to every value in array, make into string
print join(', ', @array), "\n";
# set index in array
$array[1] = 9;
# foreach loop
for my $elem (@array) {
}
foreach my $elem (@array) {
}
for (@array) {
	$_; # $_ is the elem in the array
} 
# length of array
say scalar @array;
# assign variables to array values
my ($arr0, $arr1, $arr2) = @array;
# pop last value of array
say pop @array;
# push value to end of array
say push @array, 10;
# pop first value of array
say shift @array;
# push value to start of array
say unshift @array, 0;
# remove values from array
# splice array, index, count
splice @array, 0, 3;
my $names = "kevin bob michael";
# make an array by splitting every value between //
# split every space
my @namearr = split / /, $names;
# reverse array
@array = reverse @array;
# sort array
@array = sort @array;
@array = reverse sort @array;
# create array based on contition
# this one gets all odds
my @newarr = grep {$_ % 2} @array;
# do something to every element in array
@newarr = map {$_ * 2} @newarr;

# hashes
# define
my %hashmap = ('key'=>'value', 'key2'=>'value2');
# access value
say $hashmap{'key2'};
# set value
$hashmap{'key3'} = 'value3';
# delete value
delete $hashmap{'key2'};
# test if key exists, returns true/false
exists $hashmap{'key'};
# cycle through hash
while (my ($k, $v)= each %hashmap) {
}
# convert hash to array
my @hasharr = %hashmap;
# get values from hash and put them on array
my @values = @hashmap{'key', 'key3'};
# for each key in the map
for my $k (keys %hashmap) {
}

# functions
sub func0 {
	return 'val';
}
say func0();
# parameters
sub func {
	# you can pass multiple parameters and set them here
	my ($param, $param2) = @_;
	$param ||= 'default';
	$param2 ||= 'default';
	return $param . $param2;
}
say func('passed param');
# indeterminate amount of parameters
sub func2 {
	foreach my $val (@_) {
	}
}
# function retains value across calls
sub func3 {
	state $staticvar = 0;
	say ++$staticvar;
}
func3();
func3();
# return multiple values
sub func4 {
	return 'val1', 'val2';
}
my ($func4val1, $func4val2) = func4();
say $func4val1 . $func4val2;

# file i/o
my $file = 'file.txt';
# read
open my $fh, '<', $file
	or die "cant open file: $_";
while (my $line = <$fh>) {
	chomp $line;
	my ($name, $status, $id) = split / /, $line;
	say "$name is a $status and has the id $id";
}
close $fh or die "couldnt close: $_";
# append
open my $fh, '>>', $file
	or die "cant open file: $_";
print $fh "name status id\n";
close $fh or die "couldnt close: $_";
# read and write
open my $fh, '+<', $file
	or die "cant open file: $_";
# go to position in file
seek $fh, 0, 0;
print $fh "kevin student 180005\n";
close $fh or die "couldnt close: $_";

# object oriented stuff
# import libraries
use lib 'test';
use testlibrary::testlib;
# create object and use functions
my $testobj = new testlibrary::testlib("hello", "var2");
say $testobj->getVar1();
say $testobj->getVar2();
say $testobj->setVar1('var1');
use testlibrary::inheirclass;
my $testobj2 = new testlibrary::inheirclass("hello2", "var2");
say $testobj2->getVar1();
say $testobj2->getVar2();