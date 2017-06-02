#!/bin/bash

filename="./config_files/config_compile.txt"

while read -r line
do
	pero="$line"
done < "$filename"

echo Compiling
echo $pero

g++ $pero -o test
