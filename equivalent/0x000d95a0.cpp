// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d95a0 @ 0x000d95a0
#include "decls/address.h"
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct TextBank { int FUN_000f7d30(void*); const unsigned short* FUN_000f7220(int); };
struct Menu_d95a0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextBank* v44();
 void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, void*, void*);
};
struct State_d95a0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d95a0* FUN_00086280(); };
extern void* DAT_004de648;
extern const char* DAT_004a0ce0;
extern const char* DAT_004a0ce4;
extern const char* DAT_004a0ce8;
extern void* DAT_004a0c60;
extern float DAT_003f335c;
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*);
struct Screen_d95a0 {
 char pad0[0x21c]; int field21c; char pad1[0x3b0-0x220]; unsigned char field3b0; char pad2[0x3eb-0x3b1]; unsigned char field3eb;
 Menu_d95a0* FUN_000fc3d0();
 void target(int);
};
void Screen_d95a0::target(int) {
 unsigned int cookie=DAT_004d9968;
 unsigned short text[512];
 Menu_d95a0* menu = FUN_000fc3d0();
 TextBank* bank = menu->v44();
 int id = bank->FUN_000f7d30(DAT_004de648);
 const unsigned short* source = bank->FUN_000f7220(id);
 FUN_000fc020(text,512,source);
 const char* heading;
 if(field3eb) heading=DAT_004a0ce8;
 else if(DAT_004dd6ec->FUN_00086280()->flag) heading=DAT_004a0ce4;
 else heading=DAT_004a0ce0;
 void* style=DAT_004a0c60;
 menu->FUN_000be310(heading,text,&DAT_003f335c,&DAT_003f335c,"TBS_MENU_ITEM_OK",2,style,style);
 field3b0=1;
 field21c=0;
 __security_check_cookie(cookie);
}