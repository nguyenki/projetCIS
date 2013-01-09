#!/bin/bash

r=( $(openssl rand 100000 | sha1sum) ); 
echo "${r[0]:0:15}";
