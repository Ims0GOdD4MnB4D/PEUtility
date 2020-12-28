#!/bin/bash

function error {
	echo "Error: $1" >> /dev/stderr
	exit 1
}

function wrongTypeArgument { 
	echo "Wrong type argument error: $1" >> /dev/stderr
	exit 1
}

function wrongAmountArguments {
	echo "Error: wrong amount of arguments" >> /dev/stderr
	exit 1
}
