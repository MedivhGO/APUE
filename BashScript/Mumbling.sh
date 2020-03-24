#!/bin/bash
accum () {
    # your code
    str=$1
    strlen=${#str}
    ans=""
    for((i=1;i<=strlen;++i)); do
      tmp=""
      c=${str:i-1:1}
      for((j=1;j<=i;++j)); do
          tmp=$tmp$c
      done
      tmp=${tmp,,}
      tmp=${tmp^}
      ans=$ans"-"$tmp
    done
    ans=${ans:1}
    echo $ans
}
accum "$1"