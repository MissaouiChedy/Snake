#!/bin/bash
kill -9 `ps -e | grep 'snake' | cut -d ' ' -f 2`
