// STATUS: equivalent (tools/equiv.py level 3: 17337 inputs, branch coverage 4/4)
// FUN_000d8dd0 @ 0x000d8dd0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Manager_d8dd0;
struct Provider_d8dd0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Manager_d8dd0* v44(); void FUN_000be310(const char*, unsigned short*, const float*, const float*, const float*, int, const char*, const char*); };
struct Manager_d8dd0 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
struct State_d8dd0 { char pad[0x1bc8]; unsigned char active; };
struct Singleton_4dd6ec { State_d8dd0* FUN_00086280(); };
struct Widget_d8dd0 { void FUN_000bc9f0(const char*, int); };
extern Provider_d8dd0* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(unsigned short*, int, const char*);
struct Target_d8dd0 { char pad0[0x150]; Widget_d8dd0* widget; char pad1[0x21c-0x154]; int value; char pad2[0x3b0-0x220]; unsigned char enabled; char pad3[0x3eb-0x3b1]; unsigned char mode; void run(int); };
void Target_d8dd0::run(int) {
 unsigned short buffer[512];
 Provider_d8dd0* p=FUN_000fc3d0();
 Manager_d8dd0* m=p->v44();
 int id=m->FUN_000f7d30((*(const char**)&DAT_004a0c74));
 const char* text=m->FUN_000f7220(id);
 FUN_000fc020(buffer,512,text);
 p=FUN_000fc3d0();
 const char* label;
 if(mode) label=(*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->active) label=(*(const char**)&DAT_004a0ce4);
 else label=(*(const char**)&DAT_004a0ce0);
 p->FUN_000be310(label,buffer,((float*)&DAT_003f335c),((float*)&DAT_003f335c),((float*)&DAT_003f335c),3,(*(const char**)&DAT_004a0c60),(*(const char**)&DAT_004a0c60));
 Widget_d8dd0* w=widget;
 enabled=1;
 value=0;
 w->FUN_000bc9f0("DynamicControlButtonLabel",0);
}
