// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000d94e0 @ 0x000d94e0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct State_d94e0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d94e0* FUN_00086280(); };
struct Label_d94e0 { void FUN_000bc9f0(const char*, int); };
struct Service_d94e0 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
void FUN_000be310(const char*, char*, const float*, const float*, const float*, int, unsigned int, unsigned int);
};
struct Target_d94e0 {
char pad0[0x150]; Label_d94e0* label; char pad1[0xc8]; unsigned int value; char pad2[0x190]; unsigned char active; char pad3[0x3a]; unsigned char mode;
Service_d94e0* FUN_000fc3d0();
void target(int);
};
void Target_d94e0::target(int) {
char buffer[1024];
Service_d94e0* service=FUN_000fc3d0();
service->v44();
const char* text;
if(mode) text=(*(const char**)&DAT_004a0ce8);
else if(DAT_004dd6ec->FUN_00086280()->flag) text=(*(const char**)&DAT_004a0ce4);
else text=(*(const char**)&DAT_004a0ce0);
static const float zero=0.0f;
unsigned int setting=(*(unsigned int*)&DAT_004a0c60);
service->FUN_000be310(text,buffer,&zero,&zero,&zero,3,setting,setting);
active=1;
value=0;
label->FUN_000bc9f0("DynamicControlButtonLabel",0);
}