#include "uclasses.h"
//__________________________________ TAF __________________________________

_TAF::_TAF()
{
  PVAPZ = false;
  RD = 0;
}

_TAF::~_TAF()
{
}

smallint _TAF::_AF(const bool SBRN, const smallint VH, const smallint TF,   //245.1
  const smallint AMX)  //245.2
{  //245.3
     /*Тело метода*/
//такт включения 100 мс
  smallint DELTA;  //245.6
  int PER;  //245.7
  if (SBRN)  //245.8
  {  //245.9
    RD = VH;  //245.10
    return RD;  //245.11
  }  //245.12
  else  //245.13
  {  //245.14
     if (!PVAPZ)  //245.15
     {  //245.16
        PVAPZ=true;  //245.17
        RD = VH;  //245.18
        return RD;  //245.19
     }  //245.20
     PER=VH-RD;  //245.21
//////////////////////////////
  DELTA = PER > 32767? 32767 : (PER < -32767? -32767 : PER);  //245.23
//////////////////////////////
     if (abs(DELTA) >= AMX)  //245.25
     {  //245.26
	 if (DELTA > 0)  DELTA=AMX;  //245.27
           else DELTA=-AMX;  //245.28
     }  //245.29
        if ((TF <= (10*32767/100)) || (abs(DELTA)<=6)) /*вместо 10 - 0.1*/  //245.30
  {  //245.31
       RD = VH;  //245.32
       return RD;  //245.33
     }  //245.34
 if (abs(smallint((DELTA*10/TF)*32767/100)) >1) /*вместо 10 - 0.1*/  //245.35
  {  //245.36
      RD = smallint(RD+((float)DELTA*10/TF)*32767/100);  /*вместо 10 - 0.1*/  //245.37
       return RD;  //245.38
     }  //245.39
     if   (DELTA>0)     RD++;  //245.40
                  else  RD--;  //245.41
     return RD;  //245.42
  }//if (SBRN)  //245.43
}  /*_TAF::_AF*/  //245.44



//__________________________________ TMinHyst __________________________________

_TMinHyst::_TMinHyst()
{
  old = false;
  prin = false;
}

_TMinHyst::~_TMinHyst()
{
}

bool _TMinHyst::_MinHyst(const smallint CP, const smallint Min,  //463.1
  const smallint Delta)  //463.2
{   /*Тело метода*/  //463.3
  if (!prin)  //463.4
  {  prin = true;  //463.5
     old = CP < Min;  //463.6
  }  //463.7
  old = old && (CP <= (Min + Delta)) || (CP < Min);  //463.8
  return old;  //463.9
}  //463.10
    //{_TMinHyst._MinHyst}




//__________________________________ TMaxHyst __________________________________

_TMaxHyst::_TMaxHyst()
{
  old = false;
  prin = false;
}

_TMaxHyst::~_TMaxHyst()
{
}

bool _TMaxHyst::_MaxHyst(const smallint CP, const smallint Max,   //461.1
  const smallint Delta)  //461.2
{  //461.3
  /*Тело метода*/
   if (!prin)  //461.5
    {  //461.6
      prin  = true;  //461.7
      old  = (CP > Max);  //461.8
    }  //461.9
  old = old && (CP >= (Max - Delta)) || (CP > Max);  //461.10
  return old;  //461.11
}  /*_TMaxHyst::_MaxHyst*/  //461.12


//__________________________________ TSTrigger __________________________________

_TSTrigger::_TSTrigger()
{
  St = false;
}

_TSTrigger::~_TSTrigger()
{
}

void _TSTrigger::_STrigger(const bool S, const bool R, bool &_1, bool &_0)  //449.1
{  //449.2
  /*Тело метода*/
   St = St && (!R) || S;  //449.4
   _1 = St;  //449.5
   _0 = !St;  //449.6
}  /*_TSTrigger::_STrigger*/  //449.7



//__________________________________ TOnDelay __________________________________

_TOnDelay::_TOnDelay()
{
  Count = 0;
  Pd = false;
}

_TOnDelay::~_TOnDelay()
{
}

bool _TOnDelay::_OnDelay(const bool Front, const smallint T)  //430.1
{  //430.2
  /*Тело метода*/
   if (!Front)  //430.4
   {  //430.5
       Count = 0;  //430.6
       Pd = false;  //430.7
       return false;  //430.8
   }  //430.9
  else  //430.10
   if ((Count < T) && (!Pd))  //430.11
   {  //430.12
         Count++;  //430.13
         return false;  //430.14
   }  //430.15
   else  //430.16
   {  //430.17
        Pd = true;  //430.18
        return true;  //430.19
   }  //430.20
}  /*_TOnDelay::_OnDelay*/  //430.21


//__________________________________ TAVR __________________________________

_TAVR::_TAVR()
{
  RAB1_St = new _TSTrigger();
  RAB1 = false;
  RAB2 = false;
  REZ1 = false;
  RAB3 = false;
  REZ2 = false;
  REZ3 = false;
  RAB21 = false;
  RAB22 = false;
  RAB23 = false;
  RAB2_St = new _TSTrigger();
  RAB3_St = new _TSTrigger();
  ZD_OnD = new _TOnDelay();
}

_TAVR::~_TAVR()
{
}

void _TAVR::_AVR(smallint P, bool PF, smallint PMX1, smallint PMX2, smallint PMN, bool N1RAB, bool N2RAB, 
  bool N3RAB, bool VKL1, bool OTKL1, bool VKL2, bool OTKL2, bool VKL3, bool OTKL3, bool ZDZAK, smallint TVOTKL, 
  bool N1AO, bool N2AO, bool N3AO, bool &N1A01, bool &N1A02, bool &N2A01, bool &N2A02, bool &N3A01, bool 
  &N3A02, bool &PBMX1, bool &PBMX2, bool &PNMN12)
{
  bool _43_R = false;
  bool _41_R = false;
  bool _61_R = false;
  bool _42_R = false;
  bool _62_R = false;
  bool _40_R = false;
  bool _60_R = false;
  bool _53_R = false;
  bool _54_R = false;
  bool _67_R = false;
  bool _56_R = false;
  bool _1_1 = false;
  bool _1_0 = false;
  bool _51_R = false;
  bool _52_R = false;
  bool _66_R = false;
  bool _0_1 = false;
  bool _0_0 = false;
  bool _55_R = false;
  bool _68_R = false;
  bool _2_1 = false;
  bool _2_0 = false;
  bool _73_R = false;
  bool _74_R = false;
  bool _79_R = false;
  bool _75_R = false;
  bool _76_R = false;
  bool _80_R = false;
  bool _77_R = false;
  bool _78_R = false;
  bool _81_R = false;
  bool _47_R = false;
  bool _48_R = false;
  bool _49_R = false;
  bool _50_R = false;
  bool _63_R = false;
  bool _82_R = false;
  bool _64_R = false;
  bool _83_R = false;
  bool _65_R = false;
  bool _44_R = false;
  bool _57_R = false;
  bool _45_R = false;
  bool _58_R = false;
  bool _46_R = false;
  bool _59_R = false;
  bool _69_R = false;
  bool _72_R = false;
  bool _84_R = false;
  bool _91_R = false;
  bool _88_R = false;
  bool _89_R = false;
  bool _70_R = false;
  bool _90_R = false;
  bool _93_R = false;
  bool _85_R = false;
  bool _86_R = false;
  bool _71_R = false;
  bool _87_R = false;
  bool _92_R = false;
  bool _3Out = false;
  bool _94_R = false;
  bool _95_R = false;
  bool _96_R = false;

  _43_R = RAB1 || RAB2 || RAB3;  //15.172
  _41_R = ! RAB2;  //15.184
  _61_R = _43_R && _41_R && N2RAB;  //15.185
  RAB22 = _61_R;
  _42_R = ! RAB3;  //15.189
  _62_R = _43_R && _42_R && N3RAB;  //15.190
  RAB23 = _62_R;
  _40_R = ! RAB1;  //15.179
  _60_R = _43_R && _40_R && N1RAB;  //15.180
  RAB21 = _60_R;
  _53_R = ! N1RAB;  //15.147
  _54_R = ! N3RAB;  //15.148
  _67_R = N2RAB && _53_R && _54_R;  //15.146
  _56_R = ! N2RAB;  //15.151
  RAB2_St->_STrigger(_67_R,_56_R,_1_1,_1_0);  //15.170
  RAB2 = _1_1;
  _51_R = ! N2RAB;  //15.140
  _52_R = ! N3RAB;  //15.141
  _66_R = N1RAB && _51_R && _52_R;  //15.139
  RAB1_St->_STrigger(_66_R,_53_R,_0_1,_0_0);  //15.125
  RAB1 = _0_1;
  _55_R = ! N1RAB;  //15.150
  _68_R = N3RAB && _55_R && _56_R;  //15.149
  RAB3_St->_STrigger(_68_R,_54_R,_2_1,_2_0);  //15.171
  RAB3 = _2_1;
  _73_R = ! RAB1;  //15.199
  _74_R = ! RAB21;  //15.200
  _79_R = _73_R && _74_R;  //15.195
  REZ1 = _79_R;
  _75_R = ! RAB2;  //15.203
  _76_R = ! RAB22;  //15.204
  _80_R = _75_R && _76_R;  //15.202
  REZ2 = _80_R;
  _77_R = ! RAB3;  //15.206
  _78_R = ! RAB23;  //15.207
  _81_R = _77_R && _78_R;  //15.205
  REZ3 = _81_R;
  _47_R = P > PMX1;  //15.121
  PBMX1 = _47_R;
  _48_R = P > PMX2;  //15.122
  PBMX2 = _48_R;
  _49_R = P < PMN;  //15.210
  PNMN12 = _49_R;
  _50_R = ! PF;  //15.245
  _63_R = _47_R && _50_R;  //15.246
  _82_R = _63_R && RAB1 && OTKL1;  //15.211
  _64_R = _48_R && _50_R;  //15.247
  _83_R = OTKL1 && RAB21 && _64_R;  //15.216
  _65_R = _49_R && _50_R;  //15.248
  _44_R = RAB1 || RAB21;  //15.348
  _57_R = N1AO && _44_R;  //15.349
  _45_R = RAB2 || RAB22;  //15.346
  _58_R = N2AO && _45_R;  //15.347
  _46_R = RAB3 || RAB23;  //15.344
  _59_R = N3AO && _46_R;  //15.345
  _69_R = _57_R || _58_R || _59_R;  //15.350
  _72_R = _65_R || _69_R;  //15.234
  _84_R = OTKL1 && REZ1 && _72_R;  //15.214
  _91_R = _82_R || _83_R || _84_R;  //15.215
  N1A01 = _91_R;
  _88_R = _63_R && RAB3 && OTKL3;  //15.226
  _89_R = OTKL3 && RAB23 && _64_R;  //15.229
  _70_R = _65_R || _69_R;  //15.236
  _90_R = OTKL3 && REZ3 && _70_R;  //15.227
  _93_R = _88_R || _89_R || _90_R;  //15.228
  N3A01 = _93_R;
  _85_R = _63_R && RAB2 && OTKL2;  //15.219
  _86_R = OTKL2 && RAB22 && _64_R;  //15.222
  _71_R = _65_R || _69_R;  //15.235
  _87_R = OTKL2 && REZ2 && _71_R;  //15.220
  _92_R = _85_R || _86_R || _87_R;  //15.221
  N2A01 = _92_R;
  _3Out = ZD_OnD->_OnDelay(ZDZAK,TVOTKL);  //15.238
  _94_R = _3Out && VKL1;  //15.239
  N1A02 = _94_R;
  _95_R = _3Out && VKL2;  //15.240
  N2A02 = _95_R;
  _96_R = _3Out && VKL3;  //15.241
  N3A02 = _96_R;
}

