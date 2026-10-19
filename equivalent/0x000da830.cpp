// STATUS: equivalent (tools/equiv.py level 3: 18320 inputs, branch coverage 4/4)
// FUN_000da830 @ 0x000da830
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Context;
struct Manager_da830 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Context* v44(); void FUN_000be310(const char*,char*,const float*,const float*,const char*,int,const char*,const char*); };
struct Context { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
struct Item_da830 { char pad[0x38]; const char* FUN_000f83f0(Context*,int); };
struct State_da830 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_da830* FUN_00086280(); };
extern void __cdecl FUN_000fc020(char*,int,const char*,const char*);
struct Target_da830 { char pad0[0x21c]; int field21c; char pad1[0x13c]; Item_da830 items[1]; char pad2[0x1c]; unsigned char active; char pad3[0x3a]; unsigned char mode; Manager_da830* FUN_000fc3d0(); void run(int index); };
void Target_da830::run(int index) { char buffer[1024]; Manager_da830* manager=FUN_000fc3d0(); Context* context=manager->v44(); const char* format=context->FUN_000f7220(context->FUN_000f7d30((*(const char**)&DAT_004a0cdc))); const char* value=items[index].FUN_000f83f0(context,0); FUN_000fc020(buffer,512,format,value); const char* text; if(mode) text=(*(const char**)&DAT_004a0ce8); else { State_da830* state=DAT_004dd6ec->FUN_00086280(); text=state->flag?(*(const char**)&DAT_004a0ce4):(*(const char**)&DAT_004a0ce0); } const char* option=(*(const char**)&DAT_004a0c60); manager->FUN_000be310(text,buffer,((float*)&DAT_003f335c),((float*)&DAT_003f335c),"TBS_MENU_ITEM_OK",2,option,option); active=1; field21c=0;  }
