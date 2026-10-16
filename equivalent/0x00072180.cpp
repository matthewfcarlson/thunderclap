// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_00072180 @ 0x00072180
#include "decls/data/game/global.h"

inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_000688f0(); void FUN_00068900(); void FUN_00068910(); void FUN_00068920();
class CDriftTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (*callback)();
 int tail;
 void FUN_00234960(const char*);
};
}
void __cdecl FUN_002347b0(void*,void*,int);
void FUN_00072180() {
 if (DAT_004dcfcc == 0) {
  fight::ParamFloatConstRange<CDriftTrack>* items[4];
  const char* names[4] = {"timeBegin", "timeEnd", "minVelocity", "maxVelocity"};
  void (*callbacks[4])() = {FUN_000688f0,FUN_00068900,FUN_00068910,FUN_00068920};
  for (int i=0;i<4;++i) {
   fight::ParamFloatConstRange<CDriftTrack>* p=(fight::ParamFloatConstRange<CDriftTrack>*)FUN_0008d690(24);
   if(p) {
    p->FUN_00234960(names[i]);
    p = new(p) fight::ParamFloatConstRange<CDriftTrack>;
    p->callback=callbacks[i];
   }
   items[i]=p;
  }
  FUN_002347b0(&DAT_004dcfc8,items,4);
 }
 ++DAT_004dcfcc;
}