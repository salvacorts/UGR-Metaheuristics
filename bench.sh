#!/bin/bash

echo > bench-$2.out

for amount in `seq 10 5 1000`; do
	out=`./bin/main $1 $amount`
	printf "$amount\t$out\t\t$3\n"
	printf "$amount\t$out\n" >> bench-$2.out

	if [[ "$out" -eq "$3" ]]; then
		break
	fi
done
