#!/bin/bash

function strlen {

	echo "${#1}"
}

function interactive_strlen {

	printf "Enter string >>\n"
	read str
	echo "${#str}"
}

