#!/bin/bash

function reverse {
	
	! file_ver $1 && error "current ( $1 ) file doesn't exist"
	! file_ver $2 && touch $2
	! readable_ver $1 && error "current ( $1 ) file cannot be read"
	! writetable_ver $2 && error "current ( $2 ) file cannot be written"
	
	rev "$1" > n
	tac n > "$2"
	rm n
}

function interactive_reverse {
	while :
	do
		echo "Enter file with reversing text >> "
		read revfrom
		file_ver $revfrom && break
		if readable_ver $revfrom ; then
			interactive_error "file $revfrom is not readable"
		else
			interactive_error "file $revfrom does not exist"
		fi		
	done
	while :
	do
		echo "Enter file with reversed text >> "
		read revto
		if ! file_ver $revto ; then
			touch $revto
		fi
		if ! writetable_ver $revto ; then 
			interactive_error "file $revto is not writetable"
		else 
			break
		fi
	done
	reverse $revfrom $revto

}
