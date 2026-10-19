// STATUS: equivalent (tools/equiv.py level 3: 18061 inputs, branch coverage 4/4)
// FUN_000da480 @ 0x000da480
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Texts_da480 { int FUN_000f7d30(const char*); int FUN_000f7220(int); };
struct Format_da480 { int FUN_000f83f0(Texts_da480*, int); };
struct Menu_da480 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Texts_da480* v44(); void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, const char*, const char*); };
struct State_da480 { char pad[0x1bc8]; unsigned char enabled; };
struct Singleton_4dd6ec { State_da480* FUN_00086280(); };
void __cdecl FUN_000fc020(unsigned short*, int, int, int);
struct Object { char p0[0x21c]; int field21c; char p1[0x3b0-0x220]; unsigned char field3b0; char p2[0x3eb-0x3b1]; unsigned char field3eb; char p3[8]; Format_da480 format; Menu_da480* FUN_000fc3d0(); void target(int); };
void Object::target(int) { unsigned short buffer[512]; Menu_da480* menu=FUN_000fc3d0(); Texts_da480* texts=menu->v44(); int id=texts->FUN_000f7d30((*(const char**)&DAT_004a0cd0)); int text=texts->FUN_000f7220(id); int fmt=format.FUN_000f83f0(texts,0); FUN_000fc020(buffer,512,text,fmt); const char* label; if(field3eb) label=(*(const char**)&DAT_004a0ce8); else { State_da480* state=DAT_004dd6ec->FUN_00086280(); label=state->enabled ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0); } const char* extra=(*(const char**)&DAT_004a0c60); menu->FUN_000be310(label,buffer,&DAT_003f335c,&DAT_003f335c,"TBS_MENU_ITEM_OK",2,extra,extra); field3b0=1; field21c=0;  }
