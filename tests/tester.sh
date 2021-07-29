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
	'9 8 1 6 5'
	'9 8 1 2 3'
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
printf "\n\n${ORANGE}Now some tests with random numbers from /dev/urandom${NC}\n"

NUM="`od -An -N4 -i < /dev/urandom`"
for i in `seq 1 2`; do
	NUM+="`od -An -N4 -i < /dev/urandom`"
done
printf "3 random num ($NUM)\n"
./push_swap $NUM | wc -l
RET=`./push_swap $NUM | ./checker_Mac $NUM`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi

NUM5="`od -An -N4 -i < /dev/urandom`"
for i in `seq 1 4`; do
	NUM5+="`od -An -N4 -i < /dev/urandom`"
done
printf "5 random num ($NUM5)\n"
./push_swap $NUM5 | wc -l
RET=`./push_swap $NUM5 | ./checker_Mac $NUM5`
if [ $RET = "OK" ]; then
	printf "$GREEN CHECKER : $RET $NC\n"
else
	printf "$RED CHECKER : $RET $NC\n"
fi


: '
printf "\n${PURP}double | 1 2 1 -43 |${NC}\n"
./push_swap 1 2 1 -43

printf "\n${PURP}triple | 1 2 2 3 2 |${NC}\n"
./push_swap 1 2 2 3 2

printf "\n${PURP}Not only number | 1 7 98 nn |${NC}\n"
./push_swap 1 7 98 nn

printf "\n${PURP}Strange with minus | -4-8-7 |${NC}\n"
./push_swap -4-8-7

printf "\n${PURP}Letter in number | -7Lb98 |${NC}\n"
./push_swap -7Lb98

printf "\n${PURP}Bigger than int | 1 2 2147483649 |${NC}\n"
./push_swap 1 2 2147483649

printf "\n${PURP}Lower than int | 1 2 -2147483649 |${NC}\n"
./push_swap 1 2 2147483649

printf "\n${ORANGE}already short | -14 1 2 3 4 5 6 7 41 87 |${NC}\n"
./push_swap -14 1 2 3 4 5 6 7 41 87

printf "\n${ORANGE}only one | 1 |${NC}\n"
./push_swap 1
./push_swap 1 | ./checker_Mac 1

LIST="455 -7"
printf "\n${ORANGE}very very short | $LIST |${NC}\n"
./push_swap $LIST
RET=`./push_swap $LIST | ./checker_Mac $LIST`
printf "CHECKER MAC : $RET\n"

printf "\n${ORANGE}very short | 455 1 -7 |${NC}\n"
./push_swap 455 1 -7

printf "\n${ORANGE}normal | 1 7 +81 -4 |${NC}\n"
./push_swap 1 7 81 -4

printf "\n${ORANGE}0 inside | 1 2 0 3 |${NC}\n"
./push_swap 1 2 0 3

printf "\n${ORANGE}from subject | 2 1 3 6 5 8 |${NC}\n"
./push_swap 2 1 3 6 5 8

printf "\n${LBLUE}with \"\" | \"2 1 3 6 5 8\" |${NC}\n"
./push_swap "2 1 3 6 5 8"
'


#declare -A arr=([pou]="'pouet'" [cho]="cacao")
#declare -p arr
#for key in "${!arr[@]}"; do
#	echo "$key->${arr[$key]}"
#done