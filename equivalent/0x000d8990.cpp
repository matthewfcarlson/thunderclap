// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d8990 @ 0x000d8990
#include "decls/address.h"
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
struct Manager_d8990;
struct Entry_d8990 {
 char prefix[0x1c]; unsigned char marked; char suffix[0x1b];
 const char* FUN_000f83f0(Manager_d8990*, int);
};
struct Manager_d8990 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
 virtual Manager_d8990* slot44();
 int FUN_000f7d30(const char*);
 const char* FUN_000f7220(int);
 void FUN_000be310(const char*, char*, const float*, const char*, const char*, int, const char*, const char*);
};
extern Manager_d8990* __cdecl FUN_000fc3d0();
extern void __cdecl FUN_000fc020(char*,int,const char*,const char*);
struct Settings_d8990 { char pad[0x1bc8]; unsigned char active; };
struct Singleton_4dd6ec { Settings_d8990* FUN_00086280(); };
extern const char *DAT_004a0cb8, *DAT_004a0ce0, *DAT_004a0ce4, *DAT_004a0ce8, *DAT_004a0c60;
extern const float DAT_003f335c;
struct Screen_d8990 {
 char pad0[0x21c]; int state; char pad1[0x13c]; Entry_d8990 entries[2]; char pad2[0x1f]; unsigned char mode;
 void FUN_000d8990(int index);
};
void Screen_d8990::FUN_000d8990(int index) {
 unsigned int cookie = DAT_004d9968;
 char text[1024];
 Manager_d8990* manager = FUN_000fc3d0()->slot44();
 int key = manager->FUN_000f7d30(DAT_004a0cb8);
 const char* format = manager->FUN_000f7220(key);
 const char* value = entries[index].FUN_000f83f0(manager,0);
 FUN_000fc020(text,512,format,value);
 Manager_d8990* ui = FUN_000fc3d0();
 const char* title;
 if(mode) title = DAT_004a0ce8;
 else if(DAT_004dd6ec->FUN_00086280()->active) title = DAT_004a0ce4;
 else title = DAT_004a0ce0;
 const char* callback = DAT_004a0c60;
 ui->FUN_000be310(title,text,&DAT_003f335c,"TBS_MENU_ITEM_LS_OVERWRITE","TBS_CANCEL",2,callback,callback);
 entries[1].marked = 1;
 state = 0;
 __security_check_cookie(cookie);
}
