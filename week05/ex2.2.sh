#!/bin/bash

N=$1

echo 1 > ex2.2.txt

chmod u+r+x inc_with_lock.sh

for (( i = 1; i <= $N; i++ ))
do
./inc_with_lock.sh ex2.2.txt&
./inc_with_lock.sh ex2.2.txt
done
