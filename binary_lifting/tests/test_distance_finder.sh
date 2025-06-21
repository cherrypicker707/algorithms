TIMEFMT="%E"

t=1000
n=2000

make

for i in {1..$t}
do
	printf "\033[1mTest case \033[1;96m$i\033[0m/\033[1;96m$t\033[0m\n" &&

	echo $n | tests/bin/generate_random_tree > tests/res/input.txt &&

	printf "Depth-first search solution: \033[96m" &&
	{ time tests/bin/find_distance < tests/res/input.txt > tests/res/output_brutal.txt; } 2>&1 | tr -d '\n' &&
	printf "\033[0m\n" &&

	printf "Binary lifting solution: \033[96m"
	{ time bin/find_distance < tests/res/input.txt > tests/res/output_binary_lifting.txt; } 2>&1 | tr -d '\n' &&
	printf "\033[0m\n" &&

	cmp --silent tests/res/output_brutal.txt tests/res/output_binary_lifting.txt &&
	printf "\033[1;92mSuccess!\033[0m\n\n" ||
	printf "\033[1;91mFailure!\033[0m\n\n"
done
