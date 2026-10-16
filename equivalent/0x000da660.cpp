// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000da660 @ 0x000da660
#include "decls/address.h"
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct TextSource_da660 {
 int FUN_000f7d30(const char*);
 const unsigned short* FUN_000f7220(int);
};
struct Menu_da660 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextSource_da660* v44();
 void FUN_000be310(const char*, const unsigned short*, const char*, const char*, const char*, int, const char*, const char*);
};
struct Formatter_da660 { int FUN_000f83f0(TextSource_da660*, int); };
struct State_da660 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_da660* FUN_00086280(); };
extern const char *DAT_004a0cd8, *DAT_004a0ce0, *DAT_004a0ce4, *DAT_004a0ce8, *DAT_004a0c60;
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*, int);
struct Object {
 char pad0[0x21c]; int value; char pad1[0x3b0-0x220]; unsigned char active; char pad2[0x3eb-0x3b1]; unsigned char mode; char pad3[8]; Formatter_da660 formatter;
 Menu_da660* FUN_000fc3d0();
 void target(int);
};
void Object::target(int) {
 unsigned int cookie = DAT_004d9968;
 unsigned short buffer[512];
 Menu_da660* menu = FUN_000fc3d0();
 TextSource_da660* source = menu->v44();
 int key = source->FUN_000f7d30(DAT_004a0cd8);
 const unsigned short* text = source->FUN_000f7220(key);
 int format = formatter.FUN_000f83f0(source, 0);
 FUN_000fc020(buffer, 512, text, format);
 const char* heading;
 if(mode) heading = DAT_004a0ce8;
 else { State_da660* state = DAT_004dd6ec->FUN_00086280(); heading = state->flag ? DAT_004a0ce4 : DAT_004a0ce0; }
 const char* option = DAT_004a0c60;
 menu->FUN_000be310(heading, buffer, "", "", "TBS_MENU_ITEM_OK", 2, option, option);
 active = 1;
 value = 0;
 __security_check_cookie(cookie);
}