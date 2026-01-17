#!/bin/bash

# Read from the file file.txt and output the tenth line to stdout.
file=$(cat file.txt)
linec=1
IFS=$'\n'

for line in $file;
do
    if [ $linec == 10 ]
	then
        echo ${line}
		break;
	fi
	linec=$(($linec + 1))
done;
