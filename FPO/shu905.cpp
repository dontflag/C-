#include "uobjects.h"
#include "globals.h"
#include "shu905.h"

void _FILTR()
{
  smallint _1D = 0;
  smallint _0D = 0;

  _1D = _M255_AF->_AF(_M255SBRN,_M255R,_M255TF,_M255AMX);  //2.324
  _M255D = _1D;
  _0D = _MXXX_AF->_AF(_MXXXSBRN,_MXXXR,_MXXXTF,_MXXXAMX);  //2.15
  _MXXXD = _0D;
}

void _BLOK_ZD()
{
  bool _1B = false;
  bool _0B = false;
  bool _16_R = false;
  bool _17_R = false;
  bool _15_R = false;
  bool _18_R = false;

  _1B = _L1PR_MxH->_MaxHyst(_MXXXD,_MXXX1PR,52);  //4.72
  _PI12AB01TS = _1B;
  _0B = _RQ13_BO->_MinHyst(_M255D,_M255UMN,409);  //4.86
  _P3OTSPPMN = _0B;
  _16_R = ! _PLPVD7AW;  //4.307
  _17_R = _1B && _16_R;  //4.397
  _RN21S06ZBZ = _17_R;
  _RN21S05ZBZ = _17_R;
  _15_R = ! _P3OTSPPW;  //4.305
  _18_R = _0B && _15_R;  //4.306
  _RQ13S01ZBO = _18_R;
}

void _AVR()
{
  bool _0N1A01 = false;
  bool _0N1A02 = false;
  bool _0N2A01 = false;
  bool _0N2A02 = false;
  bool _0N3A01 = false;
  bool _0N3A02 = false;
  bool _0PBMX1 = false;
  bool _0PBMX2 = false;
  bool _0PNMN12 = false;

  _RN17_AVR->_AVR(_M255D,_M255F,_M255PMX1,_M255PMX2,_M255PMN,_RN17D01RAB,_RN17D02RAB,_RN17D03RAB,_RN17D01VKL,
    _RN17D01OTKL,_RN17D02VKL,_RN17D02OTKL,_RN17D03VKL,_RN17D03OTKL,_RQ13S01ZAK,_RN17OTKLTV,_RN17D01AOF,
    _RN17D02AOF,_RN17D03AOF,_0N1A01,_0N1A02,_0N2A01,_0N2A02,_0N3A01,_0N3A02,_0PBMX1,_0PBMX2,_0PNMN12);  //13.242
  _RN17D01ZBO = _0N1A01;
  _RN17D01ZBZ = _0N1A02;
  _RN17D02ZBO = _0N2A01;
  _RN17D02ZBZ = _0N2A02;
  _RN17D03ZBO = _0N3A01;
  _RN17D03ZBZ = _0N3A02;
  _P3OTSPPMX1 = _0PBMX1;
  _P3OTSPPMX2 = _0PBMX2;
  _P3OTSPPMN12 = _0PNMN12;
}

void _TC()
{
  bool _17_R = false;
  bool _18_R = false;
  bool _19_R = false;
  bool _20_R = false;
  bool _21_R = false;

  _17_R = _TPN1B02;  //6.32
  _PI21AC01TS = _17_R;
  _18_R = _TPN2B02;  //6.33
  _PI21AD03TS = _18_R;
  _19_R = _TPNOTKL;  //6.34
  _PI21AE05TS = _19_R;
  _20_R = _RN17D01NCU || _RN17D02NCU || _RN17D03NCU;  //6.58
  _PI12AB09TS = _20_R;
  _21_R = _RN17D01A01F || _RN17D01A02F || _RN17D02A01F || _RN17D02A02F || _RN17D03A01F || _RN17D03A02F;  //6.57
  _PI12AB05TS = _21_R;
}

void _shu905()
{

  _FILTR();  //1.3
  _BLOK_ZD();  //1.5
  _AVR();  //1.90
  _TC();  //1.7
}

