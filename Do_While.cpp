#include "uobjects.h"
#include "globals.h"
#include "Do_While.h"

smallint _Do_While_Proc(const smallint X, const smallint Y)  //12.1
{  //12.2
smallint Z;  //12.3
  /*Тело функции*/
  do  //12.5
  {	  //12.6
    X++;  //12.7
    while (X > 4)  //12.8
    {  //12.9
      Y = X - Y;  //12.10
      Z = Y - (X * 3);  //12.11
      if (X > Y)  //12.12
        break;  //12.13
    }	  //12.14
    if (X > 10)  //12.15
      break;  //12.16
  }	  //12.17
  while (X < Y);  //12.18
  return Z;  //12.19
}  /*_Do_While_Proc*/  //12.20


void _Do_While()
{
  smallint _3Z = 0;

  _3Z = _Do_While_Proc(_M698,_M701);  //11.23
  _M255D = _3Z;
}

