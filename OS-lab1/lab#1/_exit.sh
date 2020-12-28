#!/bin/bash

function _exit {
	[[ $# -eq 1 ]] && int_ver $1 && exit $1
	[[ $# -eq 1 ]] && wrongTypeArgument "$1 is not int" 
}

function interactive_exit {
		[[ $# -eq 0 ]] && exit 0
		[[ $# -eq 1 ]] && int_ver $1 && exit $1
		[[ $# -eq 1 ]] && interactive_WTA "$1 is not int" 
		[[ $# > 1 ]] && interactive_WAA
}

	
