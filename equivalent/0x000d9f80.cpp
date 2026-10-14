// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d9f80 @ 0x000d9f80
struct Resource_d9f80 { int FUN_000f7d30(void*); void* FUN_000f7220(int); };
struct Menu_d9f80 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual Resource_d9f80* v44();
 void FUN_000be310(void*,char*,float*,const char*,const char*,int,void*,void*);
};
struct Status_d9f80 { char pad[0x1bc8]; unsigned char flag; };
struct Manager_d9f80 { Status_d9f80* FUN_00086280(); };
struct Entry_d9f80 { char pad[0x38]; void* FUN_000f83f0(Resource_d9f80*,int); };
extern Manager_d9f80* DAT_004dd6ec;
extern void* DAT_004de658;
extern void* DAT_004a0ce0; extern void* DAT_004a0ce4; extern void* DAT_004a0ce8; extern void* DAT_004a0c60;
extern float DAT_003f335c;
extern unsigned int DAT_004d9968;
// equiv-conv: __security_check_cookie ecx
void __cdecl __security_check_cookie(unsigned int);
extern void __cdecl FUN_000fc020(char*,int,void*,void*);
struct Target_d9f80 {
 char pad0[0x21c]; int state; char pad1[0x13c]; Entry_d9f80 entries[2]; char pad2[0x1f]; unsigned char special;
 Menu_d9f80* FUN_000fc3d0();
 void FUN_000d9f80(int index);
};
void Target_d9f80::FUN_000d9f80(int index) {
 unsigned int cookie = DAT_004d9968;
 char text[1024];
 Menu_d9f80* menu = FUN_000fc3d0();
 Resource_d9f80* resource = menu->v44();
 int id = resource->FUN_000f7d30(DAT_004de658);
 void* format = resource->FUN_000f7220(id);
 void* value = entries[index].FUN_000f83f0(resource,0);
 FUN_000fc020(text,512,format,value);
 void* label;
 if (special) label = DAT_004a0ce8;
 else { Status_d9f80* status = DAT_004dd6ec->FUN_00086280(); label = status->flag ? DAT_004a0ce4 : DAT_004a0ce0; }
 void* option = DAT_004a0c60;
 menu->FUN_000be310(label,text,&DAT_003f335c,"TBS_MENU_ITEM_CONTINUE_WITHOUT_SAVE","TBS_MENU_ITEM_RETRY",2,option,option);
 entries[1].pad[0x1c] = 1;
 state = 0;
 __security_check_cookie(cookie);
}
