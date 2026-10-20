// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 6/6)
// FUN_001dc4a0 @ 0x001dc4a0
#include "decls/data/game/global.h"

struct Vec_1dc4a0 { float x,y,z; };
struct Vec_1dc4a0;
struct Result_1dc4a0 { void FUN_0022c3b0(Vec_1dc4a0*, Vec_1dc4a0*); };
struct CSPManager_1dc4a0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual Result_1dc4a0* query(); };
struct Transform_1dc4a0 { char data[16]; void FUN_0022b4d0(Vec_1dc4a0*,Vec_1dc4a0*); };
struct Part_1dc4a0 { void FUN_001db820(Transform_1dc4a0*); };
struct Entry_1dc4a0 { char pad[16]; Part_1dc4a0 part; char p2[7]; CSPManager_1dc4a0* object; char p3[6]; short index; char p4[4]; };
struct Flag_1dc4a0 { unsigned char bits; char pad[19]; };
extern float __cdecl FUN_00224ea0(float,float);
struct Owner_1dc4a0 { char pad[0x608]; Entry_1dc4a0 entries[1932]; int FUN_001dbfe0(int); float target(int); };
float Owner_1dc4a0::target(int id) { Vec_1dc4a0 out; Transform_1dc4a0 temp; int n=FUN_001dbfe0(id); if(n<0) return 0.0f; Entry_1dc4a0& e=entries[n]; Flag_1dc4a0* flags=(Flag_1dc4a0*)this; if((flags[e.index+0x104e].bits&1) && e.object) { e.object->query()->FUN_0022c3b0(((Vec_1dc4a0*)&DAT_004c6194),&out); } else { e.part.FUN_001db820(&temp); temp.FUN_0022b4d0(((Vec_1dc4a0*)&DAT_004c6194),&out); } return FUN_00224ea0(out.x,out.z)*57.2957763671875f; }