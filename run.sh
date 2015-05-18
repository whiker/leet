#! /bin/sh
clear

exename="./a.out"

if [ -f $exename ]; then
	rm $exename
fi
make

if [ -f $exename ]; then
	clear
	$exename
fi