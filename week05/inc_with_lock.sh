#!/bin/bash

FileName="$1"

# If creating file .lock is sucess then we dont enter the while, otherwise 
# we stay in the while, while we cant create such file
# 2>/dev/null for not printing rubbish to the console

while ! ln "$FileName" "$FileName.lock" 2>/dev/null
do
	sleep 0.1
done

# .lock file created we can operate securely (hard link)

last=$( tail -n 1 "$FileName" )

((last++))

echo $last >> $FileName

# after operations we remove the lock file
rm "$FileName.lock"
