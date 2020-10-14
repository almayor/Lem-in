#!/bin/sh

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
	generator="./generator-linux"
elif [[ "$OSTYPE" == "darwin"* ]]; then
	generator="./generator-osx"
else
	echo "Operating system no supported."
	exit 1
fi

echo "\n################# EXAMPLE MAPS ##################\n"

for i in {1..20}; do
	printf "flow-one-$i:\n > " i
	$generator --flow-one | ./lem-in | ./check-solution
done

for i in {1..20}; do
	printf "flow-ten-$i:\n > " i
	$generator --flow-ten | ./lem-in | ./check-solution
done

for i in {1..20}; do
	printf "flow-thousand-$i:\n > " i
	$generator --flow-thousand | ./lem-in | ./check-solution
done

for i in {1..20}; do
	printf "big-$i:\n > " i
	$generator --big | ./lem-in | ./check-solution
done

for i in {1..20}; do
	printf "big-superposition-$i:\n > " i
	$generator --big-superposition | ./lem-in | ./check-solution
done

echo "\n############### ERROR MANAGEMENT ################\n"

maps=$(find example-maps -type f -path "*error-management*" -name "err*\.txt")
for map in $maps; do
	printf "%s:\n > " $map
	./lem-in < $map 2>&1 1>/dev/null | grep -i 'error' &> /dev/null
	if [ $? == 0 ]; then
		echo "\033[92mCorrect\033[0m"
	else
		echo "\033[91mIgnored error\033[0m"
	fi
done

maps=$(find example-maps -type f -path "*error-management*" -name "noerr*\.txt")
for map in $maps; do
	printf "%s:\n > " $map
	./lem-in < $map 2>&1 1>/dev/null | grep -i 'error' &> /dev/null
	if [ $? == 0 ]; then
		echo "\033[91mShoudn't return error\033[0m"
	else
		echo "\033[92mCorrect\033[0m"
	fi
done

echo "\n#################### TIMING #####################\n"

for i in {1..20}; do
	printf "flow-one-$i:\n > " i
	$generator --flow-one | time ./lem-in > /dev/null
	echo
done

for i in {1..20}; do
	printf "flow-ten-$i:\n > " i
	$generator --flow-ten | time ./lem-in > /dev/null
	echo
done

for i in {1..20}; do
	printf "flow-thousand-$i:\n > " i
	$generator --flow-thousand | time ./lem-in > /dev/null
	echo
done

for i in {1..20}; do
	printf "big-$i:\n > " i
	$generator --big | time ./lem-in > /dev/null
	echo
done

for i in {1..20}; do
	printf "big-superposition-$i:\n > " i
	$generator --big-superposition | time ./lem-in > /dev/null
	echo
done
