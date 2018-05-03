#!/bin/bash

echo > bench-$2.out

# for (( amount=50000; amount<=50000000; amount*=2 )); do
# 	out=`./bin/main $1 $amount`
# 	printf "$amount\t$out\t\t$3\n"
# 	printf "$amount\t$out\n" >> bench-$2.out

# 	if [[ "$out" -eq "$3" ]]; then
# 		break
# 	fi
# done


for problem in `ls -v instancias/*.dat`; do
	out=`./bin/main $problem`
	printf "$problem\t$out\n"
 	echo "$out" >> bench-$1.out	
done