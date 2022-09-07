//{Header}   {Source}
//JHGL_H --> JHGL_C

#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include "JHGL.h"

char* getJHGLVersion();
int OpenX11Window(int Border_width, int width , int height , int x , int y);
Window CreateX11Window(Display *disp , int Border_width , int width , int height , int x , int y);
GC create_GC(Display* disp , Window win , int invert_color);


Window Glob_window;
GC Glob_gc;
char *display_name;
Display *Glob_display; 
int Glob_screen;
XEvent Glob_xevent;
bool ProgramIsRunning;

//-------------------------------------------------------------------------
char* getJHGLVersion()
{
 return "JHGL version = \'beta 0.1\'";
}
//-------------------------------------------------------------------------
int OpenX11Window(int Border_width, int width , int height , int x , int y)
{

   int screen_width , screen_height;
   display_name = getenv("DISPLAY");
                           //End of variables
 
                           //Start Implementation
   Glob_display = XOpenDisplay(display_name);
   if (Glob_display == NULL)
      {
        fprintf(stderr, "JHGL.c : cannot connect to X server '%s'\n", display_name);
        exit(1);
      }

   Glob_screen = DefaultScreen(Glob_display);
   screen_width = DisplayWidth(Glob_display , Glob_screen);
   screen_height = DisplayHeight(Glob_display , Glob_screen);

   printf("window width = '%d'; height = '%d'\n",width , height);

   Glob_window = CreateX11Window(Glob_display , Border_width , width , height , x , y);
   Glob_gc = create_GC(Glob_display , Glob_window , 0);

   XSync(Glob_display , False);

   XFlush(Glob_display);
  
   XSelectInput(Glob_display , Glob_window , ExposureMask | 
                KeyPressMask | KeyReleaseMask | Button1MotionMask);
   
   ProgramIsRunning = true;
   while (ProgramIsRunning == true)
     {
        XNextEvent(Glob_display , &Glob_xevent);
        if(Glob_xevent.type == Expose)
          {
            onWindowOpen();
          }
        if(Glob_xevent.type == KeyPress)
          {
            onKeyPressed();
          }
     }

   XCloseDisplay(Glob_display);
   return 0;
}
//-------------------------------------------------------------------------
Window CreateX11Window(Display *disp , int Border_width , int width , int height , int x , int y)
{
  int screen = DefaultScreen(disp);
  Window win;

  win = XCreateSimpleWindow(disp, RootWindow(disp, screen), 
                               x , y , width , height , Border_width ,
                               WhitePixel(disp , screen), BlackPixel(disp, screen));
 
  XMapWindow(disp, win);
  XFlush(disp);
  
  return win;
}
//-------------------------------------------------------------------------
GC create_GC(Display* disp , Window win , int invert_color)
{
  GC local_gc;
  unsigned long valuemask = 0;
  
  XGCValues gcvalues;

  unsigned int line_width = 2;
  int line_style = LineSolid;
  int cap_style = CapButt;
  int join_style = JoinBevel;
  int screen = DefaultScreen(disp);      

  local_gc = XCreateGC(disp , win , valuemask , &gcvalues);
  if (local_gc < 0)
        {
         fprintf(stderr , "XCreateGC: \n");
        }
 
  if (invert_color)
  {
    XSetForeground(disp , local_gc , WhitePixel(disp , screen));
    XSetBackground(disp , local_gc , BlackPixel(disp , screen));
  }
  else
  {
    XSetForeground(disp , local_gc , BlackPixel(disp , screen));
    XSetBackground(disp , local_gc , WhitePixel(disp , screen));
  }

   XSetLineAttributes(disp , local_gc , line_width , line_style , cap_style , join_style);
   XSetFillStyle(disp , local_gc , FillSolid);    
   
   return local_gc;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void DrawLine(unsigned int color , int x1 , int y1 , int x2 , int y2)
{
  XSetForeground(Glob_display , Glob_gc , color);
  XDrawLine(Glob_display , Glob_window , Glob_gc , x1 ,y1 ,x2 ,y2);
}

//DrawPixel
//DrawRect

bool GetKey(char key)
 {
   if(Glob_xevent.xkey.keycode == (int) key)
        return true;
   else
        return false;
 }

void Terminate()
 {
  ProgramIsRunning = false; 
 }






