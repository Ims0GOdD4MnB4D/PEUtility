#!/bin/bash

function calc {
	! int_ver $2 && wrongTypeArgument "$2 is not int"
	! int_ver $3 && wrongTypeArgument "$3 is not int"	
	case $1 in 
		"sum") echo "$(($2+$3))";;
		"sub") echo "$(($2-$3))";;
		"mul") echo "$(($2*$3))";;
		"div") [[ "$3" -eq 0 ]] && error "division by zero."
			echo "$(($2/$3))";;
		*) error "command not found."
	esac
}

	
function interactive_calc {
while :
do
	printf "Choose operator: \n1. sum\n2. sub\n3. mul\n4. div\n >>\n"
	read operator
	operator_ver $operator "sum" || operator_ver $operator "sub" || operator_ver $operator "mul" || operator_ver $operator "div" && break
	interactive_error "operator not found"
done
while :
do
	printf "Enter 1st argument >>\n"
	read arg1
	! [[ $arg1 -eq $arg1 ]] 2>/dev/null && interactive_WAA && continue 
	int_ver $arg1 && break
	interactive_WTA "$arg1 is not int"		
done

while : 
do
	printf "Enter 2nd argument >>\n"
	read arg2
	! [[ $arg2 -eq $arg2 ]] 2>/dev/null && interactive_WAA && continue 
	if [[ $operator == div ]] && [[ $arg2 -eq 0 ]] ; then
		interactive_error "division by zero"
		continue
	fi
	int_ver $arg2 && break
	interactive_WTA "$arg2 is not int"
done

calc $operator $arg1 $arg2
}
