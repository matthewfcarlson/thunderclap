// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d9a80 @ 0x000d9a80
struct TextTable {
 int FUN_000f7d30(const char*);
 const unsigned short* FUN_000f7220(int);
};
struct Dialog_d9a80 {
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
 virtual TextTable* slot44();
 void FUN_000be310(const char*, const unsigned short*, const float*, const float*, const char*, int, const char*, const char*);
};
struct Status_d9a80 { char pad[0x1bc8]; unsigned char active; };
struct Manager_d9a80 { Status_d9a80* FUN_00086280(); };
extern Manager_d9a80* DAT_004dd6ec;
extern const char* DAT_004a0cb0;
extern const char* DAT_004a0ce0;
extern const char* DAT_004a0ce4;
extern const char* DAT_004a0ce8;
extern const char* DAT_004a0c60;
extern float DAT_003f335c;
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*);
struct Screen_d9a80 {
 char pad0[0x21c]; int state;
 char pad1[0x3b0-0x220]; unsigned char visible;
 char pad2[0x3eb-0x3b1]; unsigned char mode;
 Dialog_d9a80* FUN_000fc3d0();
 void FUN_000d9a80(int);
};
void Screen_d9a80::FUN_000d9a80(int) {
 unsigned short text[512];
 unsigned int cookie = DAT_004d9968;
 Dialog_d9a80* dialog = FUN_000fc3d0();
 TextTable* table = dialog->slot44();
 int id = table->FUN_000f7d30(DAT_004a0cb0);
 const unsigned short* source = table->FUN_000f7220(id);
 FUN_000fc020(text, 512, source);
 const char* heading;
 if (mode) heading = DAT_004a0ce8;
 else {
 Status_d9a80* status = DAT_004dd6ec->FUN_00086280();
 heading = status->active ? DAT_004a0ce4 : DAT_004a0ce0;
 }
 const char* option = DAT_004a0c60;
 dialog->FUN_000be310(heading, text, &DAT_003f335c, &DAT_003f335c, "TBS_MENU_ITEM_OK", 2, option, option);
 visible = 1;
 state = 0;
 __security_check_cookie(cookie);
}
