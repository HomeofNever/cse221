for i in {1..5}
do
  echo "running ping $1 -t $2 to $3${i}.log"
  ping "$1" -c "$2" > "$3${i}.log"
done
