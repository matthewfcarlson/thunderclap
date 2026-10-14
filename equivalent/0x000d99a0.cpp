// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d99a0 @ 0x000d99a0
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct TextService { int FUN_000f7d30(const char*); const unsigned short* FUN_000f7220(int); };
struct Dialog {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextService* v44();
 void FUN_000be310(const char*, unsigned short*, const float*, const float*, const char*, int, const char*, const char*);
};
struct State { char pad[0x1bc8]; unsigned char flag; };
struct Manager { State* FUN_00086280(); };
extern Manager* DAT_004dd6ec;
extern const char* DAT_004a0cb4;
extern const char* DAT_004a0ce0;
extern const char* DAT_004a0ce4;
extern const char* DAT_004a0ce8;
extern const char* DAT_004a0c60;
extern float DAT_003f335c;
void __cdecl FUN_000fc020(unsigned short*, int, const unsigned short*);
struct Screen {
 char pad0[0x21c]; int value; char pad1[0x190]; unsigned char active; char pad2[0x3a]; unsigned char alternate;
 Dialog* FUN_000fc3d0();
 void FUN_000d99a0(int);
};
void Screen::FUN_000d99a0(int) {
 unsigned int cookie = DAT_004d9968;
 unsigned short text[512];
 Dialog* dialog = FUN_000fc3d0();
 TextService* service = dialog->v44();
 int id = service->FUN_000f7d30(DAT_004a0cb4);
 const unsigned short* source = service->FUN_000f7220(id);
 FUN_000fc020(text, 512, source);
 const char* title;
 if (alternate) title = DAT_004a0ce8;
 else { State* state = DAT_004dd6ec->FUN_00086280(); title = state->flag ? DAT_004a0ce4 : DAT_004a0ce0; }
 const char* style = DAT_004a0c60;
 dialog->FUN_000be310(title, text, &DAT_003f335c, &DAT_003f335c, "TBS_MENU_ITEM_OK", 2, style, style);
 active = 1;
 value = 0;
 __security_check_cookie(cookie);
}
