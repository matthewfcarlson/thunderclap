// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000d8cb0 @ 0x000d8cb0
#include "decls/address.h"
#include "decls/data/game/global.h"
struct TextStore_d8cb0 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
struct UI_d8cb0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextStore_d8cb0* v44();
 void FUN_000be310(const char*, const unsigned short*, const char*, const char*, const char*, int, const char*, const char*);
};
UI_d8cb0* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(unsigned short*, int, const char*);
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct State_d8cb0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8cb0* FUN_00086280(); };
struct Widget_d8cb0 { void FUN_000bc9f0(const char*, int); };
struct Object {
 char pad0[0x150]; Widget_d8cb0* widget; char pad1[0x21c-0x154]; int value; char pad2[0x3b0-0x220]; unsigned char active; char pad3[0x3eb-0x3b1]; unsigned char flag;
 void target(unsigned char unused, int mode);
};
void Object::target(unsigned char unused, int mode) {
 unsigned int cookie=DAT_004d9968;
 unsigned short text[512];
 TextStore_d8cb0* store = FUN_000fc3d0()->v44();
 const char* common = (*(const char**)&DAT_004a0c60);
 int id = store->FUN_000f7d30((unsigned char)mode ? (*(const char**)&DAT_004a0c70) : (*(const char**)&DAT_004a0c6c));
 const char* source = store->FUN_000f7220(id);
 FUN_000fc020(text,512,source);
 UI_d8cb0* ui = FUN_000fc3d0();
 const char* label;
 if(flag) label=(*(const char**)&DAT_004a0ce8);
 else label=DAT_004dd6ec->FUN_00086280()->flag ? (*(const char**)&DAT_004a0ce4) : (*(const char**)&DAT_004a0ce0);
 ui->FUN_000be310(label,text,"","","",3,common,common);
 Widget_d8cb0* w = widget;
 active=1;
 value=0;
 w->FUN_000bc9f0("DynamicControlButtonLabel",0);
 __security_check_cookie(cookie);
}