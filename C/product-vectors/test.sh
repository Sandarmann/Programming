#!/bin/bash

# test all inputs

NUMTEST=0
FAILS=0
SCORE=0
SOURCEFILE="product.c"
DO_COMPILE=1
DO_CHECKSUMS=1
DO_ENCODING_CHECK=1
QUIT_ON_ERROR=0
PAD_ONLY=0
OPTIND=""
SOURCE="input"
KEYS="keys"
ENC="ENCODED"
DEC="DECODED"
GOLD="correct"
PADGOLD="padded"

function quit_on_fail()
{
	if [[ $1 == 1 ]]
	then
		exit 1
	fi

}

make_checksums()
{
	DIR=$1
	pushd $1 > /dev/null

	VERIFY="checksums/$DIR.verify"

	if [[ -f ../$VERIFY ]]
	then
		rm ../$VERIFY
	fi

	for i in *
	do
		md5sum $i >> "../$VERIFY"
	done

	popd > /dev/null

	if ! diff <(cat checksums/$DIR) <(cat $VERIFY)
	then
		echo "--------------------------------------------------"
		echo "                FATAL ERROR!"
		echo "--------------------------------------------------"
		echo "Files in $DIR do not match original test data!"
		echo "You should back up your encoder and decoder source"
		echo "code and re-extract the sample vectors tarball."
		echo "--------------------------------------------------"
		exit 1
	fi
}

usage()
{

	cat <<TEXT
	test.sh -- test your encoder/decoder
	Options:
	-x  Skip compilation step.
	-q  Quit on any error.
	-h  Print this screen.
	-c  Skip checksums check.
	-E	Test decoding only (skip "correctness" check)
	-p  Pad only (no encryption).

TEXT

	exit 0

}

maybe_quit()
{
	if [[ $QUIT_ON_ERROR == 1 ]]
	then
		if [[ $PAD_ONLY == 1 ]]
		then
			echo "Note: 'pad only' mode was selected."
		fi  
		exit 1
	fi  

}

while getopts "xqhcpE" OPTION
do
	case $OPTION in
		x)
			DO_COMPILE=0
			echo "Skipping compilation by request."
			;;
		q)
			QUIT_ON_ERROR=1
			echo "Will quit on any error."
			;;
		c)
			DO_CHECKSUMS=0
			echo "Skipping integrity check."
			;;
		p)
			PAD_ONLY=1
			echo "Attempting to perform 'padding only' (requires application support)"
			echo "Correctness is not tested!"
			;;
		E)
			DO_ENCODING_CHECK=0
			echo "Will only test decoding; encoding testing skipped."
			;;
		h)
			usage
			;;
	esac
done

if [[ $DO_CHECKSUMS == 1 ]]
then
	echo "Checking integrity of:"
	make_checksums input
	make_checksums correct
	make_checksums keys
#	make_checksums padded
	echo "Done."
fi

echo "Removing stale test data (if it exists)..."
rm $ENC/*
rm $DEC/*
rm log/*

BANNED="strcpy strcat strtok sprintf vsprintf gets strlen"

# check source code for banned functions
echo "Checking for banned functions: $BANNED"
for bfunc in $BANNED
do
	if grep -nE "\s${bfunc}\W" $SOURCEFILE &> /dev/null
	then
		echo "BANNED FUNCTION '$bfunc' DETECTED on line:"
		echo
		grep -nE "\s${bfunc}\W" $SOURCEFILE
		echo
		echo "Remove all banned functions from your code and try again."
		exit 1
	else
		echo "$bfunc"
	fi
done

if grep -nE "\sfgets\W" $SOURCEFILE &> /dev/null
then
	echo 
	echo "WARNING: You almost certainly DO NOT want to use fgets() for this project!"
	echo "Try using something like fgetc() instead!"
	echo
	sleep 10
fi

# automatically recompile encoder.c and decoder.c UNLESS
# "no_compile" is explicitly requested (FOR OFFICE USE ONLY)
if [[ $DO_COMPILE == 1 ]]
then
	if [[ ! -f $SOURCEFILE ]]
	then
		echo "'$SOURCEFILE' is missing!"
		exit 1
	fi

	if ! gcc $SOURCEFILE -o encoder -D MODE=ENCODE
	then
		echo ":-< : Failed to compile encoder! Quitting."
		exit 1
	else 
		echo ":-D : encoder.c compiled!"
	fi
	
	if ! gcc $SOURCEFILE -o decoder -D MODE=DECODE
	then
		echo ":-< : Failed to compile decoder! Quitting."
		exit 1
	else
		echo ":-D : decoder.c compiled!"
	fi
fi

for FILEPATH in $SOURCE/*
do
	FILENAME=${FILEPATH##$SOURCE/} # get basename of file

	for KEY in $KEYS/*
	do
		KEYNAME=${KEY##keys/}

		for ROUNDS in 1 2 4 8 16
		do

			for LOGFILE in log/encoder.log log/encoder.err log/decoder.log log/decoder.err
			do
				echo "----- testing $FILEPATH with key $KEY ($ROUNDS rounds) -----" >> $LOGFILE
			done

			# TEST ENCODING
			
			NUMTEST=$((NUMTEST + 1))

			if [[ $PAD_ONLY == 0 ]]
			then
				CMD="./encoder $ROUNDS $KEY $FILEPATH $ENC/$ROUNDS.$KEYNAME.$FILENAME"
				EXEMPLAR="$GOLD/$ROUNDS.$KEYNAME.$FILENAME"
			else
				CMD="./encoder $ROUNDS $KEY $FILEPATH $ENC/$ROUNDS.$KEYNAME.$FILENAME 1"
				EXEMPLAR="$PADGOLD/$ROUNDS.$KEYNAME.$FILENAME"
			fi

			if ! $CMD >> log/encoder.log 2>> log/encoder.err
			then
				echo -e "\n:-< : Encoder CRASHED!\n  Encrypting: $FILEPATH \n  with key $KEY!\n  Rounds: $ROUNDS"
				echo -e "  Command: '$CMD'\n\n"
				maybe_quit
			fi

			if [[ $DO_ENCODING_CHECK == 1 ]]
			then
				# compare the sample encoded version with your version
				if ! diff $EXEMPLAR $ENC/$ROUNDS.$KEYNAME.$FILENAME &> /dev/null
				then
					echo -e "\n:-( : Encoded file \n\t$ENC/$ROUNDS.$KEYNAME.$FILENAME != $EXEMPLAR\n"

					FAILS=$((FAILS + 1))
					maybe_quit 
				else 
					echo ":-D : Encoded $FILEPATH with key $KEY matches sample ($ROUNDS rounds). "
				fi
			else
				echo "Skipping encoding check."
			fi

			# TEST DECODING
			
			NUMTEST=$((NUMTEST + 1))

			if [[ $PAD_ONLY == 0 ]]
			then
				CMD="./decoder $ROUNDS $KEY $ENC/$ROUNDS.$KEYNAME.$FILENAME $DEC/$ROUNDS.$KEYNAME.$FILENAME"
			else
				CMD="./decoder $ROUNDS $KEY $ENC/$ROUNDS.$KEYNAME.$FILENAME $DEC/$ROUNDS.$KEYNAME.$FILENAME 1"
			fi

			if ! $CMD >> log/decoder.log 2>> log/decoder.err
			then
				echo -e "\n:-< : Decoder CRASHED!\n  Encrypting: $FILEPATH\n  with key $KEY!\n  Rounds: $ROUNDS"
				echo -e "  Command: '$CMD'\n\n"
				maybe_quit 
			fi

			# compare the sample decoded version with your decoding

			if ! diff $SOURCE/$FILENAME $DEC/$ROUNDS.$KEYNAME.$FILENAME &> /dev/null
			then

				echo -e "\n:-( : Decoded file \n\t$DEC/$ROUNDS.$KEYNAME.$FILENAME != $SOURCE/$FILENAME!\n\n"
				maybe_quit 

				FAILS=$((FAILS + 1))
			else
				echo ":-D : Decoded $FILEPATH with key $KEY matches original ($ROUNDS rounds)."
			fi

		done

	done

done

SCORE=$((NUMTEST - FAILS))
echo "You passed $SCORE out of $NUMTEST sample tests."

