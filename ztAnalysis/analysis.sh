#!/bin/bash

args=("$@")

n=$args

date

cd /home/schoenr1/work/ztAnalysis/

input=samplefiles/samplefile$n

./ztAnalysis $input $n

rm -f *.d *.so

cd -

date