#include <stdio.h>
#include <stdlib.h>
#include "JHGL.h"


int main()
{
printf("Main running for Skinnty-Download-Center ! \n"); 
OpenX11Window(2 , 500 , 500 , 10 , 10);
}


void onWindowOpen()
{
  DrawLine(0x00ff00 , 50 , 0 , 50 , 200);
}

void onKeyPressed()
{
  if (GetKey(0x09) == true)
    {
     Terminate();
    }

   if(GetKey('1') == true)
     {
        DrawLine(0x0000ff , 0 , 50 , 200 , 50);
     }
}
