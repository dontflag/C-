#ifndef uclassesH
#define uclassesH
#include "usertype.h"


//__________________________________ TAF __________________________________

class _TAF
{
public:
  bool PVAPZ;
  smallint RD;
  _TAF();
  ~_TAF();
  smallint _AF(const bool SBRN, const smallint VH, const smallint TF,   //245.1
  const smallint AMX);
};
//__________________________________ TMinHyst __________________________________

class _TMinHyst
{
public:
  bool old;
  bool prin;
  _TMinHyst();
  ~_TMinHyst();
  bool _MinHyst(const smallint CP, const smallint Min,  //463.1
  const smallint Delta);
};
//__________________________________ TMaxHyst __________________________________

class _TMaxHyst
{
public:
  bool old;
  bool prin;  //Признак первого такта выполнения
  _TMaxHyst();
  ~_TMaxHyst();
  bool _MaxHyst(const smallint CP, const smallint Max,   //461.1
  const smallint Delta);
};
//__________________________________ TSTrigger __________________________________

class _TSTrigger
{
public:
  bool St;
  _TSTrigger();
  ~_TSTrigger();
  void _STrigger(const bool S, const bool R, bool &_1, bool &_0);
};
//__________________________________ TOnDelay __________________________________

class _TOnDelay
{
public:
  smallint Count;  //Счетчик тактов задержки
  bool Pd;  //Признак окончания задержки
  _TOnDelay();
  ~_TOnDelay();
  bool _OnDelay(const bool Front, const smallint T);
};
//__________________________________ TAVR __________________________________

class _TAVR
{
public:
  _TSTrigger *RAB1_St;
  bool RAB1;
  bool RAB2;
  bool REZ1;
  bool RAB3;
  bool REZ2;
  bool REZ3;
  bool RAB21;
  bool RAB22;
  bool RAB23;
  _TSTrigger *RAB2_St;
  _TSTrigger *RAB3_St;
  _TOnDelay *ZD_OnD;
  _TAVR();
  ~_TAVR();
  void _AVR(smallint P, bool PF, smallint PMX1, smallint PMX2, smallint PMN, bool N1RAB, bool N2RAB, bool 
    N3RAB, bool VKL1, bool OTKL1, bool VKL2, bool OTKL2, bool VKL3, bool OTKL3, bool ZDZAK, smallint TVOTKL, bool 
    N1AO, bool N2AO, bool N3AO, bool &N1A01, bool &N1A02, bool &N2A01, bool &N2A02, bool &N3A01, bool &N3A02, 
    bool &PBMX1, bool &PBMX2, bool &PNMN12);
};
#endif
