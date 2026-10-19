// STATUS: equivalent (tools/equiv.py level 3: 17345 inputs, branch coverage 4/4)
// FUN_000d9680 @ 0x000d9680
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Profile_d9680 { int FUN_000f7d30(int); void* FUN_000f7220(int); };
struct Item_d9680 { char data[0x1c]; unsigned char active; char rest[0x1b]; void* FUN_000f83f0(Profile_d9680*, int); };
struct State_d9680 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9680* FUN_00086280(); };
struct Dialog_d9680 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Profile_d9680* v44();
void FUN_000be310(void*, void*, const char*, const char*, const char*, int, void*, void*);
};
     
void __cdecl FUN_000fc020(void*, int, void*, void*);
struct Object {
char pad0[0x21c]; int status; char pad1[0x35c-0x220]; Item_d9680 items[2]; char pad2[0x3eb-0x3cc]; unsigned char flag;
Dialog_d9680* FUN_000fc3d0();
void target(int index);
};
void Object::target(int index) {
char buffer[1024];
Dialog_d9680* dialog=FUN_000fc3d0();
Profile_d9680* profile=dialog->v44();
int id=profile->FUN_000f7d30(DAT_004de64c);
void* text=profile->FUN_000f7220(id);
void* item=items[index].FUN_000f83f0(profile,0);
FUN_000fc020(buffer,512,text,item);
if(flag) {
void* value=(*(void**)&DAT_004a0c60);
dialog->FUN_000be310((*(void**)&DAT_004a0ce8),buffer,"","TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_RETRY",2,value,value);
} else {
State_d9680* state=DAT_004dd6ec->FUN_00086280();
void* heading=state->flag ? (*(void**)&DAT_004a0ce4) : (*(void**)&DAT_004a0ce0);
void* value=(*(void**)&DAT_004a0c60);
dialog->FUN_000be310(heading,buffer,"","","TBS_MENU_ITEM_OK",2,value,value);
}
items[1].active=1;
status=0;
}