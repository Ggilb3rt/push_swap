#!/bin/bash

RED='\033[0;31m'
ORANGE='\033[0;33m'
LGRAY='\033[;37m'
LBLUE='\033[1;34m'
PURP='\033[0;35m'
NC='\033[0m'

printf "Test is in ${LBLUE}orange${NC} when it should works\n"
printf "Test is in ${LBLUE}blue${NC} when I don't know what is expected\n"
printf "Test is in ${PURP}purple${NC} when Error is expected\n\n"

printf "\n${ORANGE}empty${NC}\n"
./push_swap

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

printf "\n${ORANGE}normal | 1 7 +81 -4 |${NC}\n"
./push_swap 1 7 81 -4

printf "\n${ORANGE}0 inside | 1 2 0 3 |${NC}\n"
./push_swap 1 2 0 3

printf "\n${ORANGE}from subject | 2 1 3 6 5 8 |${NC}\n"
./push_swap 2 1 3 6 5 8

printf "\n${ORANGE}with \"\" | \"2 1 3 6 5 8\" |${NC}\n"
./push_swap "2 1 3 6 5 8"
