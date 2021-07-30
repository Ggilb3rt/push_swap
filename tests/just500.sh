#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
LGRAY='\033[;37m'
LBLUE='\033[1;34m'
PURP='\033[0;35m'
NC='\033[0m'

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