#!/bin/bash

for map in example-maps/err*
do
	if ./lem-in < $map 2>&1 | grep -qi "ERROR"; then
		echo "$map: passed"
	else
		echo "$map: FAILED"
		break
	fi
done

for map in example-maps/noerr*
do
	if ./lem-in < $map 2>&1 | grep -qi "ERROR"; then
		echo "$map: FAILED"
		break
	else
		echo "$map: passed"
	fi
done
