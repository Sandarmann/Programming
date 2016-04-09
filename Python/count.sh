#!/bin/bash
STR="HELLO"
numfiles=(*)
MAXSIZE=0
for ((i=0; i<${#numfiles[@]};i++)); do
	echo "${numfiles[$i]}"
	FILENAME=${numfiles[$i]}
	if [[ -d $FILENAME ]]; then
		echo "DIRECTORY"
	else
		FILESIZE=$(wc -c < $FILENAME)
		#if ["$FILESIZE" -gt "$MAXSIZE"]; then
		#	$MAXSIZE=$FILESIZE
		#fi
		#if $((FILESIZE > MAXSIZE)); then
		#   	$FILESIZE = $MAXSIZE
		#fi
		if [$FILESIZE -gt $MAXSIZE ]; then
			MAXSIZE=$FILESIZE
		fi
	fi
	#echo $FILESIZE
done
numfiles=${#numfiles[@]}
echo $MAXSIZE
#echo $numfiles
#echo $STR
