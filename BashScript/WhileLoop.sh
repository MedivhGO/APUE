#!/bin/bash
countToTwenty() {
   i=1
  while ((i<=20));do
   echo "Count: $i"
   ((i++))
   done
}

countToTwenty


#!/bin/bash

countToTwenty() {
  for i in {1..20};do echo "Count: $i" ;done
}

countToTwenty