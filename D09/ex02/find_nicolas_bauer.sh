#!/bin/sh
cat "$1" | grep -i 'Nicolas\tbauer' | grep '(*)' |  tr '\t' '.' | cut -d '.' -f 4
