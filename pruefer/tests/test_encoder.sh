TIMEFMT="%E"

t=1000
n=100000

make

for i in {1..$t}
do
	printf "\033[1mTest case \033[1;96m$i\033[0m/\033[1;96m$t\033[0m\n" &&

	echo $n | bin/generate_random_tree > tests/res/input.txt &&

	printf "Model solution: \033[96m" &&
	{ time tests/bin/encode < tests/res/input.txt > tests/res/output_module.txt; } 2>&1 | tr -d '\n' &&
	printf "\033[0m\n" &&

	printf "My solution: \033[96m"
	{ time bin/encode < tests/res/input.txt > tests/res/output_mine.txt; } 2>&1 | tr -d '\n' &&
	printf "\033[0m\n"

	cmp --silent tests/res/output_module.txt tests/res/output_mine.txt &&
	printf "\033[1;92mSuccess!\033[0m\n\n" ||
	printf "\033[1;91mFailure!\033[0m\n\n"
done
