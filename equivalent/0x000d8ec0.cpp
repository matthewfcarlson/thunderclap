// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d8ec0 @ 0x000d8ec0
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Menu_d8ec0;
struct Provider_d8ec0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Menu_d8ec0* v44();
 void FUN_000be310(const char*, const char*, const char*, const char*, const char*, int, const char*, const char*);
};
struct Menu_d8ec0 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
extern Provider_d8ec0* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(char*, int, const char*);
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
struct State_d8ec0 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d8ec0* FUN_00086280(); };
struct Target_d8ec0 {
 char p0[0x21c]; int state; char p1[0x3b0-0x220]; unsigned char active; char p2[0x3eb-0x3b1]; unsigned char mode;
 void FUN_000d8ec0(int, int);
};
void Target_d8ec0::FUN_000d8ec0(int, int) {
 unsigned int cookie = DAT_004d9968;
 char buffer[1024];
 Menu_d8ec0* menu = FUN_000fc3d0()->v44();
 int id = menu->FUN_000f7d30((*(const char**)&DAT_004a0c94));
 const char* text = menu->FUN_000f7220(id);
 FUN_000fc020(buffer, 512, text);
 Provider_d8ec0* provider = FUN_000fc3d0();
 const char* message;
 if (mode) message = (*(const char**)&DAT_004a0ce8);
 else if (DAT_004dd6ec->FUN_00086280()->flag) message = (*(const char**)&DAT_004a0ce4);
 else message = (*(const char**)&DAT_004a0ce0);
 provider->FUN_000be310(message, buffer, ((const char*)&DAT_003f335c), ((const char*)&DAT_003f335c), "TBS_MENU_ITEM_OK", 2, (*(const char**)&DAT_004a0c60), (*(const char**)&DAT_004a0c60));
 active = 1;
 state = 0;
 __security_check_cookie(cookie);
}
