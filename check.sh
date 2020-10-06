#!/bin/bash

./lem-in < $1 | tee >(grep -i required | head -1 > /dev/tty) \
			 | grep -E "L[0-9]{1,3}" | wc -l \
			 | xargs echo "Number of lines in instructions: "