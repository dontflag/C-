//Инициализация и удаление объектов
#ifndef uobjectH
#define uobjectH

#include "usertype.h"
#include "uclasses.h"

extern _TAF *_MXXX_AF;
extern _TAF *_M255_AF;
extern _TMinHyst *_RQ13_BO;
extern _TMaxHyst *_L1PR_MxH;
extern _TAVR *_RN17_AVR;

extern void InitObjects();
extern void DeleteObjects();

#endif
