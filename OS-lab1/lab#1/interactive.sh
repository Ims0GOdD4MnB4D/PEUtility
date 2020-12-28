#!bin/bash

function interactive_mode {
	while :
	do
		echo "<-----------I N T E R A C T I V E   M E N U------------>"
		printf "Functions: \n1. calc \n2. search \n3. reverse \n4. strlen \n5. log \n6. exit \n7. help \n"
		printf "Enter function number >> \n"
		read func
		case $func in 
			"1" )
				interactive_calc ;;
			"2" )
				interactive_search ;;
			"3" )
				interactive_reverse ;;
			"4" )
				interactive_strlen;;
			"5" )
				log;;
			"6" )
				while :
				do
					printf "Enter exit code >>\n"
					read exCode
					interactive_exit $exCode
				done 
				;;
			"7" )
				_help;;
			 * )
			interactive_error "Function by number $func does not exist"
		esac
		while : 
		do
			echo "Back to menu? [yes/no]"
			read command
			if [[ $command == "no" ]] ; then
				exit 0
			elif [[ $command == "yes" ]] ; then
				break
			else 
				interactive_error "command not found" 
			fi
		done
	done	
}
