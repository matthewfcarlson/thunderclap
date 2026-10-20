// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_000d8fa0 @ 0x000d8fa0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Menu_d8fa0;
struct Manager_d8fa0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Menu_d8fa0* v44();
 void FUN_000be310(const char*, const unsigned short*, const float*,const float*,const char*,int,const char*,const char*);
};
struct Menu_d8fa0 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
Manager_d8fa0* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(unsigned short*,int,const char*);
struct State_d8fa0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8fa0* FUN_00086280(); };
struct FEMemCardControl_d8fa0 { char pad[0x21c]; int field21c; char pad2[0x190]; unsigned char field3b0; char pad3[0x3a]; unsigned char field3eb; void FUN_000d8fa0(int,int); };
void FEMemCardControl_d8fa0::FUN_000d8fa0(int,int) {
 unsigned short text[512];
 Menu_d8fa0* menu=FUN_000fc3d0()->v44();
 int id=menu->FUN_000f7d30((*(const char**)&DAT_004a0c9c));
 const char* source=menu->FUN_000f7220(id);
 FUN_000fc020(text,512,source);
 Manager_d8fa0* manager=FUN_000fc3d0();
 const char* title;
 if(field3eb) title=(*(const char**)&DAT_004a0ce8);
 else if(DAT_004dd6ec->FUN_00086280()->flag) title=(*(const char**)&DAT_004a0ce4);
 else title=(*(const char**)&DAT_004a0ce0);
 const char* button=(*(const char**)&DAT_004a0c60);
 manager->FUN_000be310(title,text,&DAT_003f335c,&DAT_003f335c,"TBS_MENU_ITEM_OK",2,button,button);
 field3b0=1;
 field21c=0;
}
