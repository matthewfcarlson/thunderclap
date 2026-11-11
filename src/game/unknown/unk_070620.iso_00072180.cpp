// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00072180 FUN_00072180 (256 B): equivalent/0x00072180.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00072180 @ee47960899fa @w84bc94142ad2
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_f3a4915e {} using namespace fn_f3a4915e;
namespace fn_f3a4915e {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_00072180 @ 0x00072180


} // namespace fn_f3a4915e
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f3a4915e {

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
extern "C" void FUN_00072180() {
 if (DAT_004dcfcc == 0) {
  fight::ParamFloatConstRange<CDriftTrack>* items[4];
  const char* names[4] = {"timeBegin", "timeEnd", "minVelocity", "maxVelocity"};
  void (*callbacks[4])() = {FUN_000688f0,FUN_00068900,FUN_00068910,FUN_00068920};
  for (int i=0;i<4;++i) {
   fight::ParamFloatConstRange<CDriftTrack>* p=(fight::ParamFloatConstRange<CDriftTrack>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CDriftTrack>));
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
} // namespace fn_f3a4915e

