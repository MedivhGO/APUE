function removeChar() {
      str=$1
      len1=${#str}
      len1=$[len1-1]
      echo $str | cut -c  2-$len1
}
removeChar $1