package testlibrary::testlib;

use strict;
use warnings;

sub new {
	my $class = shift;
	my $self = {
		var => shift,
		var2 => shift
	};
	bless $self, $class;
	return $self;
}

sub getVar1 {
	my ($self) = @_;
	return $self->{var};
}
sub getVar2 {
	my ($self) = @_;
	return $self->{var2};
}

sub setVar1 {
	my ($self, $val) = @_;
	$self->{var} = $val if defined($val);
	return $self->{var};
}

1;