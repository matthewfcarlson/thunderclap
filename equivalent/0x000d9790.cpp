// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d9790 @ 0x000d9790
typedef unsigned short wchar_t;
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
struct TextTable { int FUN_000f7d30(const wchar_t*); const wchar_t* FUN_000f7220(int); };
struct Entry { char data[0x38]; const wchar_t* FUN_000f83f0(TextTable*, int); };
struct UI {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual TextTable* v44();
 void FUN_000be310(const wchar_t*,const wchar_t*,const void*,const char*,const char*,int,const wchar_t*,const wchar_t*);
};
struct State { char pad[0x1bc8]; unsigned char flag; };
struct Manager { State* FUN_00086280(); };
extern Manager* DAT_004dd6ec;
extern const wchar_t *DAT_004a0ca8,*DAT_004a0ce0,*DAT_004a0ce4,*DAT_004a0ce8,*DAT_004a0c60;
extern float DAT_003f335c;
extern void __cdecl FUN_000fc020(wchar_t*,int,const wchar_t*,const wchar_t*);
struct Object {
 char pad0[0x21c]; int status; char pad1[0x13c]; Entry entries[1]; char pad2[0x1c]; unsigned char shown; char pad3[0x3a]; unsigned char special;
 UI* FUN_000fc3d0();
 void target(int index);
};
void Object::target(int index) {
 unsigned int cookie=DAT_004d9968;
 wchar_t buffer[512];
 UI* ui=FUN_000fc3d0();
 TextTable* text=ui->v44();
 int key=text->FUN_000f7d30(DAT_004a0ca8);
 const wchar_t* format=text->FUN_000f7220(key);
 const wchar_t* item=entries[index].FUN_000f83f0(text,0);
 FUN_000fc020(buffer,512,format,item);
 const wchar_t* title;
 if(special) title=DAT_004a0ce8;
 else if(DAT_004dd6ec->FUN_00086280()->flag) title=DAT_004a0ce4;
 else title=DAT_004a0ce0;
 const wchar_t* common=DAT_004a0c60;
 ui->FUN_000be310(title,buffer,&DAT_003f335c,"TBS_INSTRUCTION_DELETE","TBS_CANCEL",2,common,common);
 shown=1;
 status=0;
 __security_check_cookie(cookie);
}
