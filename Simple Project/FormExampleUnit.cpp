//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormExampleUnit.h"
#include "Base.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormExample *FormExample;

ClassExample ObjectExemplar;
//---------------------------------------------------------------------------
__fastcall TFormExample::TFormExample(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormExample::btnMakeClick(TObject *Sender)
{
  ObjectExemplar.CalcOut();
  EdtOut->Text = IntToStr(ObjectExemplar.Out);
}
//---------------------------------------------------------------------------
