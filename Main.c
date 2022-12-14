#include <stdio.h>
#include <stdlib.h>
#include "JHGL/JHGL.h"

struct Player
{
 int x;
 int y;
 int width;
};
typedef struct Player Player;

const int WindowWidth = 1000;
const int WindowHeight = 1000;

Player player = {.width = 30 , .x = WindowHeight /2 , .y = WindowHeight /2};

int main()
{
printf("Main running for Skinny-Download-Center ! \n"); 
OpenX11Window(2 , WindowWidth , WindowHeight , 10 , 10);
}


void onWindowOpen()
{
        DrawArc(0x00ff00 , 0x0000ff , player.x , player.y , player.width , player.width , 0 , 360);
        Button btn = {.x = 10 , .y = 10 , .FontSize = 20 , .FontName = "monospace" , .FontColor="#0000ff" , .BorderColor=0x00ff00, .FillColor=0xff0000, .width=100 , .height=100 , .caption="Button"};
        DrawRectButton(btn);
}


void onKeyPressed()
{
  if (GetKey("Escape") == true)
    {
     Terminate();
    }
   else
    {
      if(GetKey("w"))
        {
          player.y += 10;
        }
      if(GetKey("s"))
        {
          player.y -= 10;
        }
      if(GetKey("d"))
        {
          player.x -= 10;
        }
      if(GetKey("a"))
        {
          player.x += 10;
        }               
      DrawFillRect(0x000000 , 0 , 0 , WindowWidth , WindowHeight);          
      DrawArc(0x00ff00 , 0x0000ff , player.x , player.y , player.width , player.width , 0 , 360);
    }
}
