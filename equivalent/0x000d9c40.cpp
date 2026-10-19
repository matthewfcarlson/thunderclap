// STATUS: equivalent (tools/equiv.py level 3: 17117 inputs, branch coverage 4/4)
// FUN_000d9c40 @ 0x000d9c40
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct TextTable { const char* FUN_000f7d30(const char*); const char* FUN_000f7220(const char*); };
extern int __cdecl FUN_000fc020(char*, int, const char*, int);
struct Screen_d9c40 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextTable* v44();
 void FUN_000be310(const char*, const char*, const float*, const char*, const char*, int, const char*, const char*);
};
extern Screen_d9c40* __cdecl FUN_000fc3d0();
struct State_d9c40 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9c40* FUN_00086280(); };
struct Control_d9c40 { void FUN_000bc9f0(const char*, int); };
struct Target_d9c40 { char p0[0x150]; Control_d9c40* control; char p1[0x21c-0x154]; int value; char p2[0x34c-0x220]; int blocks; char p3[0x3b0-0x350]; unsigned char active; char p4[0x3eb-0x3b1]; unsigned char mode; void run(); };
void Target_d9c40::run() {
 char text[1024];
 Screen_d9c40* screen=FUN_000fc3d0();
 TextTable* table=screen->v44();
 int count=4-blocks;
 const char* entry=table->FUN_000f7d30((*(const char**)&DAT_004a0cc4));
 const char* format=table->FUN_000f7220(entry);
 FUN_000fc020(text,512,format,count);
 const char* label;
 if(mode) label=(*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->flag) label=(*(const char**)&DAT_004a0ce4);
 else label=(*(const char**)&DAT_004a0ce0);
 const char* extra=(*(const char**)&DAT_004a0c60);
 screen->FUN_000be310(label,text,((float*)&DAT_003f335c),"TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_FREE_MORE_BLOCKS",2,extra,extra);
 Control_d9c40* c=control;
 active=1;
 value=0;
 c->FUN_000bc9f0("DynamicControlButtonLabel",3);
}