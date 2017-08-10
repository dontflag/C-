//Инициализация и удаление объектов
#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TAF *_MXXX_AF;
_TAF *_M255_AF;
_TMinHyst *_RQ13_BO;
_TMaxHyst *_L1PR_MxH;
_TAVR *_RN17_AVR;
void InitObjects()
{
  _MXXX_AF = new(_TAF);
  _M255_AF = new(_TAF);
  _RQ13_BO = new(_TMinHyst);
  _L1PR_MxH = new(_TMaxHyst);
  _RN17_AVR = new(_TAVR);
}
void DeleteObjects()
{
  delete(_MXXX_AF);
  delete(_M255_AF);
  delete(_RQ13_BO);
  delete(_L1PR_MxH);
  delete(_RN17_AVR);
}
