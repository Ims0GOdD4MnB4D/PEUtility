#!bin/bash

function interactive_error {

	echo "Error: $1" >> /dev/stderr
}

function interactive_WTA {

	echo "Wrong type argument error: $1" >> /dev/stderr
}

function interactive_WAA {

	echo "Error: wrong amount of arguments" >> /dev/stderr
}
