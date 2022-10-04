#!/bin/bash

#min=0
#max=1

ARG="`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`"; ./push_swap $ARG > res ; cat res | ./checker_linux $ARG ; cat res | wc -l


#check with valgrind :
#ARG="`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`" ; valgrind --leak-check=full ./push_swap $ARG

rm res
