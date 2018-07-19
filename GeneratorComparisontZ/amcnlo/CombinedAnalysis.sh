#!/bin/bash

function run_zt1(){
root -b -l << EOF
.x CombinedAnalysis.C+("ztMadgraph/unweighted_events.root","histos-ztMadgraph.root",0.001621)
.q
EOF
}

function run_zt2(){
root -b -l << EOF
.x CombinedAnalysis.C+("ztMadgraph2/unweighted_events.root","histos-ztMadgraph2.root",2.159e-05)
.q
EOF
}

function run_DucMad(){
root -b -l << EOF
.x CombinedAnalysis.C+("NTUP.schan.LHE.root","histos-DucMad.root",3.17)
.q
EOF
}


function combineHist(){
root -b -l << EOF
.x combineHist.C+()
.q
EOF
}


#run_zt1
#run_zt2
run_DucMad

#combineHist

#cp comboResults.txt results/comboResults_`eval date +%b%d`_`eval date +%T`.txt

#cp histoscombined.root results/histoscombined_`eval date +%b%d`_`eval date +%T`.root

#cp histosCombined.pdf results/histosCombined_`eval date +%b%d`_`eval date +%T`.pdf

rm -f *.d *.so