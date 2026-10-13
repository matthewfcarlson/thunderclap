// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001b6440 @ 0x001b6440
struct Part { char data[0x138]; void FUN_001b3020(); };
struct Tail { char data[0x14]; void FUN_001b6380(); };
struct CCollisionManager;
typedef void (__cdecl *Callback)();
void __cdecl FUN_001b46d0();
void __cdecl FUN_001b4cd0();
struct Command { Command* FUN_001b61f0(const char*, CCollisionManager*, Callback); };
struct Registry { void FUN_001b62d0(const char*, CCollisionManager*, Callback); void FUN_001d3b70(const char*,Command*); };
Registry* __cdecl FUN_001d4c90();
void* __cdecl FUN_0008d690(unsigned int);
struct Physics { void FUN_002ece90(int,float,int); };
extern Physics* DAT_00554c10;
struct CCollisionManager {
 virtual void slot0();
 int a,b,c;
 Part parts[4];
 int d,e,f;
 int counters[19];
 int ids[19];
 Tail tail;
 float gravity;
 CCollisionManager();
};
CCollisionManager::CCollisionManager() {
 a=0;b=0;c=0;
 for(int i=0;i<4;++i) parts[i].FUN_001b3020();
 d=0;e=0;f=0;
 tail.FUN_001b6380();
 gravity=-3000.0f;
 Registry* registry=FUN_001d4c90();
 if(registry) {
 registry->FUN_001b62d0("cm_SetGravity",this,FUN_001b46d0);
 Command* command=(Command*)FUN_0008d690(0x24);
 if(command) command=command->FUN_001b61f0("cm_AddExplosion",this,FUN_001b4cd0);
 registry->FUN_001d3b70("cm_AddExplosion",command);
 for(int j=0;j<19;++j) { counters[j]=0; ids[j]=-1; }
 DAT_00554c10->FUN_002ece90(0,gravity,0);
 }
}
