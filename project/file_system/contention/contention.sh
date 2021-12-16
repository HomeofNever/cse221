#!/bin/bash

COMMAND=""
FILESIZE="64MB"
rm contention_res.txt
for i in {1..10}
do
  cat "testFile${FILESIZE}" > "testFile${FILESIZE}_${i}.txt"
  COMMAND+="../../dist/contention testFile${FILESIZE}_${i}.txt &"
  echo "taskset --cpu-list 30 ${COMMAND}"
  eval "taskset --cpu-list 30 ${COMMAND}"
  sleep .25
done

for i in {1..10}; do rm "testFile${FILESIZE}_${i}.txt"; done