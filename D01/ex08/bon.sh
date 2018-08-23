#!/bin/sh
ldapsearch -Q "sn=*bon*" | grep -v filter | wc -l | sed "s/ //g"
