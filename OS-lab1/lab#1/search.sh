#!/bin/bash

function search {
 	! dir_ver $1 && error "directory not found."
	grep -r $2 $1 2>/dev/null
}

function interactive_search {
	while :
	do 
		echo "Enter directory >> "
		read dir
		dir_ver $dir && break
		interative_error "no such directory."
	done
	printf "Enter file name >>\n"
	read file_name
	search $dir $file_name
}	
	
