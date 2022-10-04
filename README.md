# PUSH_SWAP
School 42 project: introduction to sorting algorithms

The subject of this project is sorting algorithm.
We can only use some movement to sort a serie of number thanks to two stacks:
- sa (swap a) to swap first 2 elements of stack a.
- sb (swap b) to swap first 2 elements of stack b.
- ss (swap both) to swap first 2 element of stack a and of stack b
- pa (push a) push the first top element of stack b on the top of stack a
- pb (push b) push the first top element of stack a on the top of stack b
- ra (rotate a) shift up all element of stack a by 1. 
- rb (rotate b) shift up all element of stack b by 1.
- rr (rotate both) shift up all element of stack a and stack b by 1.
- rra (reverse rotate a) shift down all element of stack a by 1.
- rrb (reverse rotate b) shift down all element of stack b by 1.
- rrr (reverse rotate both) shift down all element of stack a and stack b by 1.

I used the radix sort for this exercise. It is not the most optimal algorithm for a small list of digits, but it has the advantage of being very stable. Indeed, all the digits are change for their place number. Ex: if I had to sort 3 | -1 | 200 | 4 | -45
The new list of numbers will look like this  2 |  1 | 4   | 3 |  0
Then these digits will be convert in binary so we can sort them by unit, then by tens, hundreds, etc. easily.

How to use it.
```
$ make
$ ./run.sh 0 100
```
You can change 0 and 100 which are respectively the minimum and the maximum digit of your number list to sort.
It will give you an OK, are KO which correspond to the response of the checker_linux program (this program is provide by 42 and tell us if numbers are correctly sorted are not). And than, it will give you a number which is the number of movement that my program do for sort numbers.
If you open the run.sh program you will see in details the command:
ARG="`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`"; ./push_swap $ARG > res ; cat res | ./checker_linux $ARG ; cat res | wc -l
The ruby command sort a non sorting list of number between my min and max number. 
