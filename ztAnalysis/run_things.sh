#!/bin/bash

cd /home/schoenr1/work/ztAnalysis/

make clean

make

mkdir -p output;

echo "made"

sleep 5 

bash Submit/GenerateSubmit.sh

bash Submit/MainSubmit.sh

echo "submitted to condor"

a=`condor_q $USER | grep -c ztAnalysis`
b=0
while [ $a -ne $b ]
  do
  sleep 10
  echo "waiting on $a jobs"
  a=`condor_q $USER |grep -c ztAnalysis`
done

sleep 5

echo "done with condor"



