#!/bin/bash

source calc.sh
source search.sh
source strlen.sh
source _exit.sh
source reverse.sh
source log.sh
source exceptions.sh
source verification.sh
source interactive.sh
source interactive_exceptions.sh
source _help.sh

case "$1" in
"calc") 
	[[ $# -ne 4 ]] && wrongAmountArguments
	calc "$2" "$3" "$4";;
"search") 
	[[ $# -ne 3 ]] && wrongAmountArguments
	search "$2" "$3";;
"strlen") 
	[[ $# -ne 2 ]] && wrongAmountArguments	
	strlen "$2";;
"reverse") 
	[[ $# -ne 3 ]] && wrongAmountArguments
	reverse "$2" "$3";;
"log") 
	[[ $# -ne 1 ]] && wrongAmountArguments
	log;;
"exit") 
	[[ $# -eq 1 ]] && exit 0
	[[ $# > 2 ]] && wrongAmountArguments	
	_exit "$2"
	;;
"interactive")
	[[ $# -ne 1 ]] && wrongAmountArguments
	interactive_mode;;
"help")
	[[ $# -ne 1 ]] && wrongAmountArguments
	_help;;
*) error "unknown command. Try use 'main.sh help'";;
esac
