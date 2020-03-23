#!/bin/bash

#!/bin/bash
repeat=$1
string=$2
ret=""
for((i=repeat;i>=1;i--)); do
      ret=$ret$string
  done
echo "$ret"
