#!bin/bash


let n=00

max=10000

while read line
  do
  #echo $line>>outfile.txt;

  echo $line>>samplefile$n
  let n=n+1
  
  #echo ${line:49:92}
  #echo ${line:141:33}
  #echo $line $n
  echo $n
done<"samplefileN"


echo $value;
    
