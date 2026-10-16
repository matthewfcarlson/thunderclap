// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 7/8, incomplete)
// FUN_001efe20 @ 0x001efe20
#include "decls/data/game/unknown.h"

typedef unsigned int uint_1efe20;
struct Key_1efe20 { uint_1efe20 a,b; void FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Entry_1efe20 { char pad[24]; float probability; void FUN_001ef2a0(uint_1efe20,uint_1efe20); };
struct Group_1efe20 { Entry_1efe20* FUN_001ef1e0(Key_1efe20*); };
extern Group_1efe20* __stdcall FUN_001efb80(uint_1efe20);
struct RandomState_1efe20 { uint_1efe20 a,b; };
extern RandomState_1efe20* __cdecl FUN_000964d0();
bool __stdcall FUN_001efe20(uint_1efe20 group,uint_1efe20 arg,const char* name,uint_1efe20 last) {
 ++(*(uint_1efe20*)&DAT_004e3728);
 Group_1efe20* g=FUN_001efb80(group);
 if (!g) { ++(*(uint_1efe20*)&DAT_004e372c); return false; }
 Key_1efe20 key; key.FUN_0027b0e0(name);
 Entry_1efe20* e=g->FUN_001ef1e0(&key);
 if (!e) { ++(*(uint_1efe20*)&DAT_004e3730); key.FUN_0027af50(); return false; }
 RandomState_1efe20* r=FUN_000964d0();
 r->a=(r->a & 65535)*0x9069+(r->a>>16);
 r->b=(r->b & 65535)*0x4650+(r->b>>16);
 uint_1efe20 value=((r->a<<16)+(r->b & 65535))%1000;
 ++(*(uint_1efe20*)&DAT_004e3734);
 if ((double)value * (double)0.1f > e->probability) { ++(*(uint_1efe20*)&DAT_004e373c); key.FUN_0027af50(); return false; }
 e->FUN_001ef2a0(arg,last);
 key.FUN_0027af50();
 return true;
}