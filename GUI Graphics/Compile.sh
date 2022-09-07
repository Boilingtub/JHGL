#!/bin/bash

#Configure
ProjectDir='/home/hendrik/Coding-Projects/C/GUI Graphics'
SrcFiles="Main.c JHGL.c"
Libraries='-L/usr/X11R6/lib -lX11'
Exename='Main'

#Procedure
cd "${ProjectDir}"
if gcc -o ${Exename} ${SrcFiles} ${Libraries}; then
        echo "compilation Success"
        ./${Exename}
else
        echo "compilation Failure"
fi  

