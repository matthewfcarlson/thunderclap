// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b6440 @ 0x001b6440
#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct Part_1b6440 { char data[0x138]; void FUN_001b3020(); };
struct Tail_1b6440 { char data[0x14]; void FUN_001b6380(); };
struct CCollisionManager;
typedef void (__cdecl *Callback_1b6440)();
void __cdecl FUN_001b46d0();
void __cdecl FUN_001b4cd0();
struct Command_1b6440 { Command_1b6440* FUN_001b61f0(const char*, CCollisionManager*, Callback_1b6440); };
struct Registry_1b6440 { void FUN_001b62d0(const char*, CCollisionManager*, Callback_1b6440); void FUN_001d3b70(const char*,Command_1b6440*); };
Registry_1b6440* __cdecl FUN_001d4c90();
void* __cdecl FUN_0008d690(hulk_uintptr);
struct Physics_1b6440 { void FUN_002ece90(int,float,int); };
struct CCollisionManager {
 virtual void slot0();
 int a,b,c;
 Part_1b6440 parts[4];
 int d,e,f;
 int counters[19];
 int ids[19];
 Tail_1b6440 tail;
 float gravity;
 CCollisionManager();
};
CCollisionManager::CCollisionManager() {
 a=0;b=0;c=0;
 for(int i=0;i<4;++i) parts[i].FUN_001b3020();
 d=0;e=0;f=0;
 tail.FUN_001b6380();
 gravity=-3000.0f;
 Registry_1b6440* registry=FUN_001d4c90();
 if(registry) {
 registry->FUN_001b62d0("cm_SetGravity",this,FUN_001b46d0);
 Command_1b6440* command=(Command_1b6440*)FUN_0008d690(0x24);
 if(command) command=command->FUN_001b61f0("cm_AddExplosion",this,FUN_001b4cd0);
 registry->FUN_001d3b70("cm_AddExplosion",command);
 for(int j=0;j<19;++j) { counters[j]=0; ids[j]=-1; }
 (*(Physics_1b6440**)&DAT_00554c10)->FUN_002ece90(0,gravity,0);
 }
}
