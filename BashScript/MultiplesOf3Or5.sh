#!/bin/bash

echo $1
n=$1
sum=0
for((i=0;i<n;++i)); do
    if((i%3==0 || i%5==0)); then
        ((sum+=i))
    fi 
done
echo $sum
