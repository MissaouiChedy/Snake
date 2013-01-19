#!/bin/bash
#Utility for killing the program process
kill -9 `ps -e | grep 'snake' | cut -d ' ' -f 2`
