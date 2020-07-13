#!/bin/sh
# This program is needed primarily because the Norme
# (the code standard @ School 42) restricts the comment format to the one that
# isn't recognised by Doxygen. Hence, a pre-processing with perl is needed.
# This script also performs post-doxygen clean-up.

command -v doxygen >/dev/null
if [ $? -ne 0 ]; then
	echo "Please install Doxygen!"
else
	find . -name "*.c" -exec perl -i -pe 's/^\/\*$/\/\*\*/' {} \;
	find . -name "*.h" -exec perl -i -pe 's/^\/\*$/\/\*\*/' {} \;
	doxygen docs/.doxygen/Doxyfile
	find . -name "*.c" -exec perl -i -pe 's/^\/\*\*$/\/\*/' {} \;
	find . -name "*.h" -exec perl -i -pe 's/^\/\*\*$/\/\*/' {} \;
fi
