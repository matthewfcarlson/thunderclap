// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 7/8, incomplete)
// FUN_001efe20 @ 0x001efe20
typedef unsigned int uint;
struct Key { uint a,b; void FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Entry { char pad[24]; float probability; void FUN_001ef2a0(uint,uint); };
struct Group { Entry* FUN_001ef1e0(Key*); };
extern Group* __stdcall FUN_001efb80(uint);
struct RandomState { uint a,b; };
extern RandomState* __cdecl FUN_000964d0();
extern uint DAT_004e3728,DAT_004e372c,DAT_004e3730,DAT_004e3734,DAT_004e373c;
bool __stdcall FUN_001efe20(uint group,uint arg,const char* name,uint last) {
 ++DAT_004e3728;
 Group* g=FUN_001efb80(group);
 if (!g) { ++DAT_004e372c; return false; }
 Key key; key.FUN_0027b0e0(name);
 Entry* e=g->FUN_001ef1e0(&key);
 if (!e) { ++DAT_004e3730; key.FUN_0027af50(); return false; }
 RandomState* r=FUN_000964d0();
 r->a=(r->a & 65535)*0x9069+(r->a>>16);
 r->b=(r->b & 65535)*0x4650+(r->b>>16);
 uint value=((r->a<<16)+(r->b & 65535))%1000;
 ++DAT_004e3734;
 if ((double)value * (double)0.1f > e->probability) { ++DAT_004e373c; key.FUN_0027af50(); return false; }
 e->FUN_001ef2a0(arg,last);
 key.FUN_0027af50();
 return true;
}