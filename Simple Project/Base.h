//---------------------------------------------------------------------------

#ifndef BaseH
#define BaseH
#include "usertype.h"
#include "uIncludes.h"
#include "FormExampleUnit.h"
#include <string>
//---------------------------------------------------------------------------
using namespace std;

class ClassExample
{
private:
  bool IsNumber(string aInp);

public:
  smallint Inp;
  smallint Out;
  smallint getInp();
  void CalcOut();
  ClassExample();
  ~ClassExample();
};
#endif
