#ifndef JHGL_H
#define JHGL_H

typedef enum { true , false} bool;

struct Struct_Button
 {
  char* caption;
  int FontSize;
  char FontColor[8];
  char* FontName;
  int x;
  int y;
  int width;
  int height;
  int BorderColor;
  int FillColor;
  void (*OnMouseLeave_FuncPtr);
  void (*OnMouseOver_FuncPtr);
  void (*OnClick_FuncPtr);
 };
typedef struct Struct_Button Button;

//UI functions
void DrawRectButton(Button btn);

//Globals
char* getJHGLVersion();
int OpenX11Window(int Border_width , int width , int height , int x , int y);


//Primitives
void DrawLine(unsigned int color ,int x1 , int y1 , int x2 , int y2);
void DrawPixel(unsigned int color , int x , int y);
void DrawRect(unsigned int BorderColor , unsigned int FillColor , int x , int y , int width , int height);
void DrawBorderRect(unsigned int color , int x , int y , int width , int height);
void DrawFillRect(unsigned int color , int x , int y , int width , int height);
void DrawBorderArc(unsigned int color , int x , int y , int width , int height , int StartAngle , int DrawAngle);
void DrawFillArc(unsigned int color , int x , int y , int width , int height , int StartAngle , int DrawAngle);
void DrawArc(unsigned int BorderColor , unsigned int FillColor , int x , int y , int width , int height , int StartAngle , int DrawAngle);
void DrawText(char* FontColor , char* FontName , unsigned short FontSize , int x , int y , char *string);

//Event Functions
void onWindowOpen();
void onKeyPressed();
void onMouseButtonDown();
void onMouseMove();
  bool GetKey(char *Inputkey);

//Exit and Return Functions  
void Terminate();
#endif
