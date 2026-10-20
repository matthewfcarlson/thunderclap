// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 10/10)
// FUN_000710c0 @ 0x000710c0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_000682e0(); void __cdecl FUN_000682f0(); void __cdecl FUN_00068300(); void __cdecl FUN_0006b750();
class CMoveAddTrack;
namespace fight { template<class T> struct ParamFloatConstRange {
 virtual void slot0(); char data[12]; void (__cdecl *callback)(); unsigned tail;
 void FUN_00234960(const char*);
}; }
 
void __cdecl FUN_002347b0(unsigned*,fight::ParamFloatConstRange<CMoveAddTrack>**,unsigned);
void __cdecl FUN_000710c0() {
 typedef fight::ParamFloatConstRange<CMoveAddTrack> Range;
 if (!DAT_004dcf54) {
 Range* items[4];
 const char* names[4] = {"timeBegin","timeEnd","distance","direction"};
 void (__cdecl *callbacks[4])() = {FUN_000682e0,FUN_000682f0,FUN_00068300,FUN_0006b750};
 for (unsigned i=0;i<4;++i) {
 Range* p = (Range*)FUN_0008d690(24);
 if(p) { p->FUN_00234960(names[i]); p->fight::ParamFloatConstRange<CMoveAddTrack>::ParamFloatConstRange(); p->callback=callbacks[i]; }
 items[i]=p;
 }
 FUN_002347b0(&DAT_004dcf50,items,4);
 }
 ++DAT_004dcf54;
}
