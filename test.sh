mkdir res
make

export LD_LIBRARY_PATH=lib
TIMEFMT="%E"

n=1000
generate="bin/xenia_and_tree/generate"
generate_parameters=(100 1000 100 1000)
solve_left="bin/xenia_and_tree/brute"
solve_right="bin/xenia_and_tree/centroid_decomposition"

for i in {1..$n}
do
    if
        $generate $generate_parameters > "res/random.in" &&
        time_left=$({ time $solve_left < "res/random.in" > "res/left.out" } 2>&1 ) &&
        time_right=$({ time $solve_right < "res/random.in" > "res/right.out" } 2>&1 ) &&
        cmp -s "res/left.out" "res/right.out" &&
        true
    then
        printf "\033[90m[\033[92mv\033[90m] \033[92msuccess! \033[90m[\033[96m$i\033[90m] "

        printf "[ \033[96m$(basename $solve_left) "
        printf "\033[90m| \033[96m$(head -n 1 res/left.out ) "
        printf "\033[90m| \033[96m$time_left \033[90m] "

        printf "[ \033[96m$(basename $solve_right) "
        printf "\033[90m| \033[96m$(head -n 1 res/right.out ) "
        printf "\033[90m| \033[96m$time_right \033[90m]\033[0m\n"
    else
        printf "\033[90m[\033[91mx\033[90m] \033[91mfailure! \033[90m[\033[96m$i\033[90m] "

        printf "[ \033[96m$(basename $solve_left) "
        printf "\033[90m| \033[96m$(head -n 1 res/left.out ) "
        printf "\033[90m| \033[96m$time_left \033[90m] "

        printf "[ \033[96m$(basename $solve_right) "
        printf "\033[90m| \033[96m$(head -n 1 res/right.out ) \033[90m| "
        printf "\033[96m$time_right \033[90m]\033[0m\n"
        break
    fi
done
