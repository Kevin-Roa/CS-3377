package testlibrary::inheirclass;

use testlibrary::testlib;
use strict;

# import functions
our @ISA = qw(testlibrary::testlib);

#override functions
sub getVar2 {
	my ($self) = @_;
	return $self->{var2} x 2;
}

1;