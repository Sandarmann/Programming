#/usr/bin/perl -w

# comments with hashtag
my $question = <STDIN>;
my $answer = function($question);
showAnser($answer);

#### functions go below here
## functions do not have a parameter limit oddly enough,
# inorder to take 
sub function{
	my ($text) = @_;
	print $text;

	return <STDIN>;
}
sub showAnser{
	my ($text) = @_;
	print $text;
}