#!/bin/sh
ldapwhoami -Q | cut -d ':' -f2

