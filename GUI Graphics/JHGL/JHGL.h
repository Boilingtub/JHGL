#ifndef JHGL_H
#define JHGL_H

typedef enum { true , false} bool;

char* getJHGLVersion();
int OpenX11Window(int Border_width , int width , int height , int x , int y);

void DrawLine(unsigned int color ,int x1 , int y1 , int x2 , int y2);
void DrawPixel(unsigned int color , int x , int y);
void DrawRect(unsigned int BorderColor , unsigned int FillColor , int x , int y , int width , int height);
void DrawBorderRect(unsigned int color , int x , int y , int width , int height);
void DrawFillRect(unsigned int color , int x , int y , int width , int height);
void DrawBorderArc(unsigned int color , int x , int y , int width , int height , int StartAngle , int DrawAngle);
void DrawFillArc(unsigned int color , int x , int y , int width , int height , int StartAngle , int DrawAngle);
void DrawArc(unsigned int BorderColor , unsigned int FillColor , int x , int y , int width , int height , int StartAngle , int DrawAngle);


void onWindowOpen();
void onKeyPressed();
  bool GetKey(char *Inputkey);

void Terminate();
#endif
