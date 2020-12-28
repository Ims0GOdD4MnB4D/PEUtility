#!/bin/bash

function log {
	
	log_file="/var/log/anaconda/X.log"
	Warning=$(cat $log_file | awk '/\[/ && /WW/') >> /dev/null	
	Information=$(cat $log_file | awk '/\[/ && /II/') >> /dev/null
	Y='\033[93m'
	B='\033[34m'
	DEF='\033[0m'
	echo -e "${Warning//"(WW)"/"${Y}Warning:${DEF}"}"
	echo -e "${Information//"(II)"/"${B}Information:${DEF}"}"
	
}
