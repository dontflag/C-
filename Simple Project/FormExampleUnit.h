//---------------------------------------------------------------------------

#ifndef FormExampleUnitH
#define FormExampleUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <dialogs.hpp>
//---------------------------------------------------------------------------
class TFormExample : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *EdtInp;
        TButton *btnMake;
        TEdit *EdtOut;
  void __fastcall btnMakeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormExample(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormExample *FormExample;
//---------------------------------------------------------------------------
#endif
