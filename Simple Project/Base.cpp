//---------------------------------------------------------------------------
#include <cctype>

#pragma hdrstop

#include "Base.h"

bool ClassExample::IsNumber(string aInp)
{
smallint i = 0;
  while (isalnum(aInp[i]))
    i++;
  if (i==strlen(aInp.c_str()))
    return true;
  else
    return false;
}

ClassExample::ClassExample()
{
  Inp = -1;
  Out = -1;
}
ClassExample::~ClassExample()
{
}
smallint ClassExample::getInp()
{
  if ((strlen(FormExample->EdtInp->Text.c_str()) > 0) & IsNumber(FormExample->EdtInp->Text.c_str()))
  {
    if (StrToInt(FormExample->EdtInp->Text) > -1)
    Inp = StrToInt(FormExample->EdtInp->Text);
  }
  else
    ShowMessage("¬ведите число!");
}
void ClassExample::CalcOut()
{
  getInp();
  if (Inp > -1)
  {
    switch (Inp)
    {
      case 0:
        Out++;
      case 1:
      {
        Out+=2;
        break;
      }
      default:
        Out -=3;
      case 2:
        Out += Inp + 7;
    }
    if (Out==1)
    {
      Out++;
    }
  }
}





//---------------------------------------------------------------------------

#pragma package(smart_init)


