#! /bin/sh
clear
exename="./a.out"

if [ -f $exename ]; then
	rm $exename
fi

g++ -std=c++11 main.cpp

if [ -f $exename ]; then
	clear
	$exename
fi