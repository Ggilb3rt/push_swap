#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
LGRAY='\033[;37m'
LBLUE='\033[1;34m'
PURP='\033[0;35m'
NC='\033[0m'

: '
for i in `seq 1 500`; do
	NUM500+="`od -An -N4 -i < /dev/urandom`"
done
printf "\n${ORANGE}500 random num $NC\n"
./push_swap $NUM500 | wc -l
#RET=`./push_swap $NUM500 | ./checker_Mac $NUM500`
#if [ $RET = "OK" ]; then
#	printf "$GREEN CHECKER : $RET $NC\n"
#else
#	printf "$RED CHECKER : $RET $NC\n"
#fi
'
echo "v2"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
./push_swap $ARG | wc -l

: '
max=0
test_nb=500
value_nb=5
min_val=1
max_val=5
for i in `seq 1 $test_nb`
do
	arg=`shuf -i $min_val-$max_val -n $value_nb`
	arg=`echo $arg | sed 's/\n/ /g'`
	current=`./push_swap $arg | wc -l`
	error=`./push_swap $arg | ./checker_linux $arg`
	if [ $error != "OK"]
	then
		echo "$arg\n$error\n" >> error
	else
		echo "$arg\n$error ($current instruction)\n" >> ok
	fi
	if [ $current -gt $max ]
	then
		max="$current"
		worst="$arg"
	fi
done
'