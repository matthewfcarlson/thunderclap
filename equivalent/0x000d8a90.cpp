// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d8a90 @ 0x000d8a90
struct UI {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual UI* v44();
int FUN_000f7d30(const char*); const char* FUN_000f7220(int);
void FUN_000be310(const char*, const unsigned short*, const float*, const char*, const char*, int, const char*, const char*);
};
UI* __cdecl FUN_000fc3d0();
void __cdecl FUN_000fc020(unsigned short*, int, const char*, const char*);
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Entry { char data[0x38]; const char* FUN_000f83f0(UI*,int); };
struct State { char pad[0x1bc8]; unsigned char flag; };
struct Manager { State* FUN_00086280(); };
extern Manager* DAT_004dd6ec;
extern const char *DAT_004a0cbc, *DAT_004a0ce0, *DAT_004a0ce4, *DAT_004a0ce8, *DAT_004a0c60;
extern const float DAT_003f335c;
struct Target { char pad0[0x21c]; int value; char pad1[0x35c-0x220]; Entry entries[1]; char pad2[0x3b0-0x394]; unsigned char active; char pad3[0x3eb-0x3b1]; unsigned char mode; void run(int index); };
void Target::run(int index) {
unsigned int cookie=DAT_004d9968;
unsigned short text[512];
UI* ui = FUN_000fc3d0()->v44();
int id = ui->FUN_000f7d30(DAT_004a0cbc);
const char* format = ui->FUN_000f7220(id);
const char* name = entries[index].FUN_000f83f0(ui,0);
FUN_000fc020(text,512,format,name);
UI* dialog = FUN_000fc3d0();
const char* title;
if(mode) title=DAT_004a0ce8;
else if(DAT_004dd6ec->FUN_00086280()->flag) title=DAT_004a0ce4;
else title=DAT_004a0ce0;
const char* extra=DAT_004a0c60;
dialog->FUN_000be310(title,text,&DAT_003f335c,"TBS_MENU_ITEM_MC_LOAD","TBS_CANCEL",2,extra,extra);
active=1;
value=0;
__security_check_cookie(cookie);
}