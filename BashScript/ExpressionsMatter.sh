a=$1
b=$2
c=$3
# your code here

ar=($( echo "$1 * ($2 + $3)" | bc )
    $( echo "$1 * $2 * $3" | bc )
    $( echo "$1 + $2 + $3" | bc )
    $( echo "$1 + $2 * $3" | bc )
    $( echo "$1 * $2 + $3" | bc )
    $( echo "($1 + $2) * $3" | bc ))
IFS=$'\n'
echo "${ar[*]}" | sort -nr | head -n1