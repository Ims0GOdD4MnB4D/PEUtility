#!bin/bash

function int_ver {

	reg='^[+-]?[0-9]+$'
	[[ $1 =~ $reg ]] 
}

function readable_ver {

	test -r "$1"
}

function writetable_ver {

	test -w "$1"
}

function operator_ver {

	test $1 == $2
}

function file_ver {

	test -f "$1"
}

function dir_ver {

	test -d "$1"
}
