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

I used the radix sort for this exercise. It is not the most optimal algorithm for a very large number of digits, but it has the advantage of being very stable. Indeed, all the digits are change for their place number. Ex: if I had to sort 3 | -1 | 200 | 4 | -45
The new list of numbers will look like this  2 |  1 | 4   | 3 |  0
