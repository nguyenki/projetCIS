#!/bin/bash

# Exctraction 
function extract
{
    
    echo bonj : Bonjour $1

    fullfilename=$(basename $1)
    extension=${fullfilename##*.}
    filename=${fullfilename%.*}
    
    echo "fullfilename=$fullfilename"
    echo "extension=$extension"
    echo "filename=$filename"
}

function check
{
}

function schedule
{
} 

