#!/bin/sh

find . -type f -name "*.sh"| sed 's/\.sh//' | rev | cut -d"/" -f 1 | rev 
