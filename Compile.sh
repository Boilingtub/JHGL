#!/bin/bash

#Configure
ProjectDir='/home/hendrik/Coding-Projects/C/GUI Graphics'
SrcFiles="Main.c JHGL/JHGL.c"
Libraries='-L/usr/X11R6/lib -lX11 -lXft -lfontconfig -I/usr/include/freetype2 -I/usr/include/libpng16'
Exename='Main'

#Procedure
cd "${ProjectDir}"
if gcc -o ${Exename} ${SrcFiles} ${Libraries}; then
        echo "compilation Success"
        ./${Exename}
else
        echo "compilation Failure"
fi  

