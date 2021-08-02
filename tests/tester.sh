#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
LGRAY='\033[;37m'
LBLUE='\033[1;34m'
PURP='\033[0;35m'
NC='\033[0m'

printf "Test is in ${ORANGE}orange${NC} when it should works\n"
printf "Test is in ${LBLUE}blue${NC} when I don't know what is expected\n"
printf "Test is in ${PURP}purple${NC} when Error is expected\n\n"

printf "\n${ORANGE}empty${NC}\n"
./push_swap

## ERRORS TESTS  
declare -a ERROR_NUM=(
	'1 2 1 -43'
	'1 2 2 3 2'
	'1 7 98 nn'
	'-4-8-7'
	'-7Lb98'
	'1 2 2147483649'
	'1 2 -2147483649'
	'1 2 --7'
)
for i in "${ERROR_NUM[@]}"; do
	printf "\n${PURP}./push_swap $i${NC}\n"
	./push_swap $i
	#./push_swap $i | ./checker_Mac $i
	#printf "CHECKER : `./push_swap $i | ./checker_Mac $i`\n"
done

declare -a PRRRT_NUM=('\"2 1 3 6 5 8\"')
for j in "${PRRRT_NUM[@]}"; do
	printf "\n${LBLUE}./push_swap $j${NC}\n"
	./push_swap $j
done

## WORKING TESTS
declare -a WORKING_NUM=(
	'-14 1 2 3 4 5 6 7 41 87'
	'1'
	'455 -7'
	'47 -8 5'
	'0 100 85'
	'1 7 +81 -4'
	'1 2 0 3'
	'2 1 3 6 5 8'
	'5 9 1 8 6'
	'9 8 1 6 5 4'
	'9 8 7 6 5 4'
)
for i in "${WORKING_NUM[@]}"; do
	printf "\n${ORANGE}./push_swap $i${NC}\n"
	./push_swap $i | wc -l
	RET=`./push_swap $i | ./checker_Mac $i`
	if [ $RET = "OK" ]; then
		printf "$GREEN CHECKER : $RET $NC\n"
	else
		printf "$RED CHECKER : $RET $NC\n"
	fi
done

## RANDOM NUMBERS TESTS
printf "\n\n${ORANGE}------------------------------------------------------\n"
printf "Now some tests with random numbers${NC}\n"

for i in `seq 0 2`; do
	NUM+="`od -An -N4 -i < /dev/urandom`"
done
printf "\n${ORANGE}3 random num $NC\n"
./push_swap $NUM | wc -l
RET=`./push_swap $NUM | ./checker_Mac $NUM`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi

for i in `seq 1 5`; do
	NUM5+="`od -An -N4 -i < /dev/urandom`"
done
printf "\n${ORANGE}5 random num $NC\n"
./push_swap $NUM5 | wc -l
RET=`./push_swap $NUM5 | ./checker_Mac $NUM5`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi

NUM100=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
printf "\n${ORANGE}100 random num $NC\n"
./push_swap $NUM100 | wc -l
RET=`./push_swap $NUM100 | ./checker_Mac $NUM100`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi

NUM500=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
printf "\n${ORANGE}500 random num $NC\n"
./push_swap $NUM500 | wc -l
RET=`./push_swap $NUM500 | ./checker_Mac $NUM500`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi


## RANDOM NUMBERS TESTS
printf "\n\n${ORANGE}------------------------------------------------------\n"
printf "Now some tests with other quantity${NC}\n"

NUM6=`ruby -e "puts (0..5).to_a.shuffle.join(' ')"`;
printf "\n${ORANGE}6 random num $NC\n"
./push_swap $NUM6 | wc -l
RET=`./push_swap $NUM6 | ./checker_Mac $NUM6`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi

NUM50=`ruby -e "puts (0..69).to_a.shuffle.join(' ')"`;
printf "\n${ORANGE}69 random num $NC\n"
./push_swap $NUM50 | wc -l
RET=`./push_swap $NUM50 | ./checker_Mac $NUM50`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi

NUM237=`ruby -e "puts (0..237).to_a.shuffle.join(' ')"`;
printf "\n${ORANGE}237 random num $NC\n"
./push_swap $NUM237 | wc -l
RET=`./push_swap $NUM237 | ./checker_Mac $NUM237`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi

#declare -A arr=([pou]="'pouet'" [cho]="cacao")
#declare -p arr
#for key in "${!arr[@]}"; do
#	echo "$key->${arr[$key]}"
#done