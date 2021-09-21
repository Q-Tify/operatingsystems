#!/bin/bash

N=$1

echo 1 > ex2.1.txt

chmod u+r+x inc.sh

for (( i = 0; i < $N; i++ ))
do
./inc.sh ex2.1.txt&
./inc.sh ex2.1.txt
done
