#! /bin/zsh

t=10
n=10000

TIMEFMT=%E

echo $n > tests/res/input.txt

printf "\033[1mComparing execution time of programs generating random tree (n = $n): \n\033[0m"

for i in {1..$t}
do
	printf "\n"

	printf "Brute-force solution: [\033[32m"
	{ time tests/bin/generate_random_tree < tests/res/input.txt > tests/res/output.txt; } 2>&1 | tr -d '\n'
	printf "\033[0m]\n"

	printf "Prüfer code solution: [\033[32m"
	{ time bin/generate_random_tree < tests/res/input.txt > tests/res/output.txt; } 2>&1 | tr -d '\n'
	printf "\033[0m]\n"
done
