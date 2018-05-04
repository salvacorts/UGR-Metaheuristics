#!/bin/bash

echo > bench-$2.out

for (( amount=10; amount<=100; amount+=10 )); do
	out=`./bin/main $1 $amount`
	printf "$amount\t$out\n"
	printf "$amount\t$out\n" >> bench-$2.out
done


# for problem in `ls -v instancias/*.dat`; do
# 	out=`./bin/main $problem`
# 	printf "$problem\t$out\n"
#  	echo "$out" >> bench-$1.out	
# done