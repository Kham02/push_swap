#!/bin/bash
YELLOW='\033[38;05;228m'
GREEN='\033[38;05;120m'
RED='\033[38;05;203m'
BLACKBACK='\033[48;05;232m'
ENDCOLOR="\033[0m"
x=1
k=$1
cou=0;
retry=20
max=0;
min=90000000000
while [ $x -le $retry ]
do
	ARG=$(python3.7 getrandom.py $k)
	# echo $ARG
	# ./push_swap $ARG | wc -l
	./push_swap $ARG | ./checker_Mac $ARG
	cur=$(./push_swap $ARG | wc -l)
	let cou=$(($cou+$cur))
	if [ $cur -gt $max ]; then
	max=$cur
	fi
	if [ $cur -le $min ]; then
	min=$cur
	fi
	x=$(( $x + 1 ))
done
cou=$(($cou/$retry));
echo -e '| '$BLACKBACK'max -> '$RED $max$ENDCOLOR '\t|'
echo -e '| '$BLACKBACK'avr -> '$YELLOW $cou$ENDCOLOR '\t|'
echo -e '| '$BLACKBACK'min -> '$GREEN $min$ENDCOLOR '\t|'
echo -e $RED
# echo -e "dublicate:"
# ./push_swap 0 +0 1 3 -4 214748364
# ./push_swap 0 1 3 -4 -0 214748364

# echo -e "\nmax int +:"
# ./push_swap 0 1 3 -4 2147483648
echo -e $ENDCOLOR
# leaks --atExit -- ./push_swap 0 1 3 -4 -2147483648

