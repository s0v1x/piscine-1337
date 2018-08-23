#!/bin/sh
ifconfig | grep "..:..:..:..:..:.." | cut -d' ' -f2

