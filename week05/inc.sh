#!/bin/bash

FileName="$1"

#Critical region
last=$( tail -n 1 "$FileName" )
#

((last++))

echo $last >> $FileName
