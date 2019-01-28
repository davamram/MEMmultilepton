#!/bin/bash

cd data/Madgraph
./SetupMadgraph.sh

cd ../../
make clean
make -j8

cd config
source setConfig.sh

cd ../Examples
make clean
make

cd ..
