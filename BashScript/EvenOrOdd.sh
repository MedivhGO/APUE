#!/bin/bash

EvenOrOdd()
{
    if(($1%2==0)); then
        echo "Even"
    else
        echo "Odd"
    fi
}
EvenOrOdd "$1"


