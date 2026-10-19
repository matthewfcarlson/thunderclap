// STATUS: equivalent (tools/equiv.py level 3: 17099 inputs, branch coverage 4/4)
// FUN_000d8a90 @ 0x000d8a90
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct UI_d8a90 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual UI_d8a90* v44();
int FUN_000f7d30(const char*); const char* FUN_000f7220(int);
void FUN_000be310(const char*, const unsigned short*, const float*, const char*, const char*, int, const char*, const char*);
};
UI_d8a90* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(unsigned short*, int, const char*, const char*);
struct Entry_d8a90 { char data[0x38]; const char* FUN_000f83f0(UI_d8a90*,int); };
struct State_d8a90 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8a90* FUN_00086280(); };
struct Target_d8a90 { char pad0[0x21c]; int value; char pad1[0x35c-0x220]; Entry_d8a90 entries[1]; char pad2[0x3b0-0x394]; unsigned char active; char pad3[0x3eb-0x3b1]; unsigned char mode; void run(int index); };
void Target_d8a90::run(int index) {
unsigned short text[512];
UI_d8a90* ui = FUN_000fc3d0()->v44();
int id = ui->FUN_000f7d30((*(const char**)&DAT_004a0cbc));
const char* format = ui->FUN_000f7220(id);
const char* name = entries[index].FUN_000f83f0(ui,0);
FUN_000fc020(text,512,format,name);
UI_d8a90* dialog = FUN_000fc3d0();
const char* title;
if(mode) title=(*(const char**)&DAT_004a0ce8);
else if(DAT_004dd6ec->FUN_00086280()->flag) title=(*(const char**)&DAT_004a0ce4);
else title=(*(const char**)&DAT_004a0ce0);
const char* extra=(*(const char**)&DAT_004a0c60);
dialog->FUN_000be310(title,text,&DAT_003f335c,"TBS_MENU_ITEM_MC_LOAD","TBS_CANCEL",2,extra,extra);
active=1;
value=0;
}