// STATUS: equivalent (tools/equiv.py level 3: 18168 inputs, branch coverage 4/4)
// FUN_000da570 @ 0x000da570
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct TextSource_da570 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
struct Menu_da570 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextSource_da570* v44(); void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, const char*, const char*); };
struct Formatter_da570 { const char* FUN_000f83f0(TextSource_da570*, int); };
struct State_da570 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_da570* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, const char*, const char*);
struct FEMemCardControl_da570 { char p0[0x21c]; int status; char p1[0x3b0-0x220]; unsigned char active; char p2[0x3eb-0x3b1]; unsigned char special; char p3[8]; Formatter_da570 formatter; Menu_da570* FUN_000fc3d0(); void FUN_000da570(int); };
void FEMemCardControl_da570::FUN_000da570(int) { unsigned short buffer[512]; Menu_da570* menu=FUN_000fc3d0(); TextSource_da570* source=menu->v44(); int id=source->FUN_000f7d30((*(const char**)&DAT_004a0cd4)); const char* text=source->FUN_000f7220(id); const char* format=formatter.FUN_000f83f0(source,0); FUN_000fc020(buffer,512,text,format); const char* title; if(special) title=(*(const char**)&DAT_004a0ce8); else { State_da570* state=DAT_004dd6ec->FUN_00086280(); title=state->flag ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0); } const char* option=(*(const char**)&DAT_004a0c60); menu->FUN_000be310(title,buffer,((float*)&DAT_003f335c),((float*)&DAT_003f335c),"TBS_MENU_ITEM_OK",2,option,option); active=1; status=0;  }
