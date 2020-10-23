#!/bin/bash

# redirecting generator output to a temporary file because pipes in
# Docker containers don't work with large input that gets printed too fast
TMPFILE=$(mktemp /tmp/abc-script.XXXXXX)

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	generator="./generator-linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then
	generator="./generator-osx"
else
	echo "Operating system no supported."
	exit 1
fi

printf "\n############### ERROR MANAGEMENT ################\n\n"

maps=$(find example-maps -type f -path "*error-management*" -name "err*\.txt")
for map in $maps; do
	printf "%s:\n > " $map
	./lem-in < $map 2>&1 1>/dev/null | grep -i 'error' &> /dev/null
	if [ $? == 0 ]; then
		printf "\033[92mCorrect\033[0m\n"
	else
		printf "\033[91mIgnored error\033[0m\n"
	fi
done

echo

maps=$(find example-maps -type f -path "*error-management*" -name "noerr*\.txt")
for map in $maps; do
	printf "%s:\n > " $map
	./lem-in < $map 2>&1 1>/dev/null | grep -i 'error' &> /dev/null
	if [ $? == 0 ]; then
		printf "\033[91mShoudn't return error\033[0m\n"
	else
		printf "\033[92mCorrect\033[0m\n"
	fi
done

printf "\n################# EXAMPLE MAPS ##################\n\n"

for i in {1..20}; do
	echo "flow-one-$i:"
	$generator --flow-one > $TMPFILE
	./lem-in < $TMPFILE | ./check-solution
done

echo

for i in {1..20}; do
	echo "flow-ten-$i:"
	$generator --flow-ten > $TMPFILE
	./lem-in < $TMPFILE | ./check-solution
done

echo

for i in {1..20}; do
	echo "flow-thousand-$i:"
	$generator --flow-thousand > $TMPFILE
	./lem-in < $TMPFILE | ./check-solution
done

echo

for i in {1..20}; do
	echo "big-$i:"
	$generator --big > $TMPFILE
	./lem-in < $TMPFILE | ./check-solution
done

echo

for i in {1..20}; do
	echo "big-superposition-$i:"
	$generator --big-superposition > $TMPFILE
	./lem-in < $TMPFILE | ./check-solution
done

printf "\n################### TIMING #####################\n\n"

for i in {1..20}; do
	printf "flow-one-$i:\n > "
	$generator --flow-one > $TMPFILE
	echo $(time ./lem-in < $TMPFILE 2>&1 >/dev/null) # echo to get nice output from time
done

echo

for i in {1..20}; do
	printf "flow-ten-$i:\n > "
	$generator --flow-ten > $TMPFILE
	echo $(time ./lem-in < $TMPFILE 2>&1 >/dev/null) # echo to get nice output from time
done

echo

for i in {1..20}; do
	printf "flow-thousand-$i:\n > "
	$generator --flow-thousand > $TMPFILE
	echo $(time ./lem-in < $TMPFILE 2>&1 >/dev/null) # echo to get nice output from time
done

echo	

for i in {1..20}; do
	printf "big-$i:\n > "
	$generator --big > $TMPFILE
	echo $(time ./lem-in < $TMPFILE 2>&1 >/dev/null) # echo to get nice output from time
done

echo

for i in {1..20}; do
	printf "big-superposition-$i:\n > "
	$generator --big-superposition > $TMPFILE
	echo $(time ./lem-in < $TMPFILE 2>&1 >/dev/null) # echo to get nice output from time
done
