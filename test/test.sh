#!/bin/sh

echo "\n################# EXAMPLE MAPS ##################\n"

# maps=$(find example-maps -type f ! -path "*error-management*" -name "*\.txt")
# for map in $maps; do
# 	printf "%s:\n > " $map
# 	./lem-in < $map | ./check-solution
# done

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

maps=$(find example-maps -type f ! -path "*error-management*" -name "big*\.txt")
for map in $maps; do
	printf "%s:\n > " $map
	time ./lem-in < $map > /dev/null
	echo
done
