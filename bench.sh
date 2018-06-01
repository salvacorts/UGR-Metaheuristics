#!/bin/bash

echo > bench-$1.out

for problem in `ls -v instancias/*.dat`; do
	out=`./bin/main $problem`
	printf "$problem\t$out\n"
 	echo "$out" >> bench-$1.out	
done