// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 14/14)
// FUN_0003ed40 @ 0x0003ed40
#include "decls/data/game/global.h"

struct Key_3ed40 { unsigned lo, hi; void FUN_0027af00(); void FUN_0027b040(const char*); void FUN_0027af70(const Key_3ed40*); };
void __cdecl FUN_00363bb0();
int __cdecl _atexit(void (__cdecl*)());
struct Source_3ed40 { float FUN_000448b0(unsigned,unsigned); };
struct Entry_3ed40 { Key_3ed40 key; float value; unsigned unused; };
struct Object { char pad0[0x11c]; Source_3ed40* source; char pad1[0x1ba8-0x120]; Entry_3ed40 entries[14]; int count; void target(const char*,float); };
void Object::target(const char* name,float value) {
 if (!(DAT_004dc2e0 & 1)) { DAT_004dc2e0 |= 1; (*(Key_3ed40*)&DAT_004dc2d8).FUN_0027af00(); _atexit(FUN_00363bb0); }
 (*(Key_3ed40*)&DAT_004dc2d8).FUN_0027b040(name);
 int n=count;
 if(n>0) { unsigned lo=(*(Key_3ed40*)&DAT_004dc2d8).lo, hi=(*(Key_3ed40*)&DAT_004dc2d8).hi; for(int i=0;i<count;++i) { if(entries[i].key.lo==lo && entries[i].key.hi==hi) { if(value == -2.0f) entries[i].value=source->FUN_000448b0(lo,hi); else entries[i].value=value; return; } } }
 if(n<14) { entries[n].key.FUN_0027af70(((Key_3ed40*)&DAT_004dc2d8)); entries[count].value=value; ++count; }
}
