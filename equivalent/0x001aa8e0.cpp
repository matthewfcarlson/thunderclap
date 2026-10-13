// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::scenario::NISAnimationAction::vfunc_3 @ 0x001aa8e0
struct Script { char pad[0x51]; unsigned char flag; };
struct Character { char pad[0xaf1]; unsigned char active; void FUN_00207b90(); };
struct Result { char pad[0xa8]; unsigned char flag; };
struct Manager { void FUN_0003dd00(int); Result* FUN_00036a80(int); void FUN_0003b620(int); };
struct World { char pad[0x124]; Manager* manager; };
struct Root { char pad[0x20]; World* world; };
extern Root* DAT_004dd700;
extern const char* __cdecl FUN_001a4cb0(Script*, int);
extern bool __cdecl FUN_001a4fd0(Script*, int);
namespace hulkfight { namespace scenario {
struct NISAnimationAction {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
char pad0[0x18]; Script* script; void* enabled; char pad1[0x1e8]; Character* character; char pad2[4]; unsigned char started;
bool FUN_001aa7d0();
};
bool NISAnimationAction::vfunc_3(int,int) {
if (!enabled) return false;
if (!character->active) { character->FUN_00207b90(); started=1; }
Manager* manager=DAT_004dd700->world->manager;
if (manager) {
manager->FUN_0003dd00(1);
Script* s=script;
int i;
for(i=0;i<20;++i) {
const char* name=FUN_001a4cb0(s,i);
if(name) {
const char* expected="hulk";
int n=0;
while(n<5 && name[n]==expected[n]) ++n;
if(n==5) break;
}
}
if(i<20) {
if(FUN_001a4fd0(s,i)) manager->FUN_0003b620(1);
} else if(!s->flag) {
Result* result=manager->FUN_00036a80(1);
result->flag=0;
}
}
return FUN_001aa7d0();
}
}}
