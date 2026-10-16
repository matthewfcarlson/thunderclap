// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d9d40 @ 0x000d9d40
#include "decls/address.h"
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
struct TextService_d9d40 { int FUN_000f7d30(const char*); const char* FUN_000f7220(int); };
struct Menu_d9d40 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextService_d9d40* v44();
void FUN_000be310(const char*, const unsigned short*, const float*, const char*, const char*, int, const char*, const char*);
};
extern Menu_d9d40* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(unsigned short*, int, const char*, const char*);
struct State_d9d40 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9d40* FUN_00086280(); };
extern const char *DAT_004a0cc8, *DAT_004a0c64, *DAT_004a0ce0, *DAT_004a0ce4, *DAT_004a0ce8, *DAT_004a0c60;
extern const float DAT_003f335c;
struct Target_d9d40 { char pad0[0x21c]; int value; char pad1[0x190]; unsigned char active; char pad2[0x3a]; unsigned char mode; void FUN_000d9d40(); };
void Target_d9d40::FUN_000d9d40() {
unsigned int cookie=DAT_004d9968;
unsigned short buffer[512];
Menu_d9d40* menu = FUN_000fc3d0();
TextService_d9d40* text = menu->v44();
const char* secondKey = DAT_004a0c64;
const char* first = text->FUN_000f7220(text->FUN_000f7d30(DAT_004a0cc8));
const char* second = text->FUN_000f7220(text->FUN_000f7d30(secondKey));
FUN_000fc020(buffer,512,first,second);
const char* title;
if(mode) title=DAT_004a0ce8;
else if(DAT_004dd6ec->FUN_00086280()->flag) title=DAT_004a0ce4;
else title=DAT_004a0ce0;
const char* key=DAT_004a0c60;
menu->FUN_000be310(title,buffer,&DAT_003f335c,"TBS_MENU_ITEM_FREE_MORE_BLOCKS","TBS_CANCEL",2,key,key);
active=1; value=0;
__security_check_cookie(cookie);
}
