// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000d9890 @ 0x000d9890
#include "decls/address.h"
#include "decls/data/game/global.h"
struct View;
struct Item_d9890 { char pad[0x1c]; unsigned char active; char tail[0x1b]; int FUN_000f83f0(View*,int); };
struct View { int FUN_000f7d30(const char*); int FUN_000f7220(int); };
struct Manager_d9890 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual View* v44(); void FUN_000be310(const char*, char*, const float*,const float*,const float*,int,const char*,const char*); };
struct State_d9890 { char pad[0x1bc8]; unsigned char flag; };
struct Singleton_4dd6ec { State_d9890* FUN_00086280(); };
struct Control_d9890 { void FUN_000bc9f0(const char*,int); };
    
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
extern void __cdecl FUN_000fc020(char*,int,int,int);
struct Target_d9890 { char p0[0x150]; Control_d9890* control; char p1[0x21c-0x154]; int field21c; char p2[0x35c-0x220]; Item_d9890 items[2]; char p3[0x3eb-0x3cc]; unsigned char flag; Manager_d9890* FUN_000fc3d0(); void run(int); };
void Target_d9890::run(int index) { char buffer[1024]; unsigned int cookie=DAT_004d9968; Manager_d9890* manager=FUN_000fc3d0(); View* view=manager->v44(); int a=view->FUN_000f7d30((*(const char**)&DAT_004a0cac)); int b=view->FUN_000f7220(a); int c=items[index].FUN_000f83f0(view,0); FUN_000fc020(buffer,512,b,c); const char* label; if(flag) label=(*(const char**)&DAT_004a0ce8); else { State_d9890* state=DAT_004dd6ec->FUN_00086280(); label=state->flag?(*(const char**)&DAT_004a0ce4):(*(const char**)&DAT_004a0ce0); } const char* value=(*(const char**)&DAT_004a0c60); manager->FUN_000be310(label,buffer,&DAT_003f335c,&DAT_003f335c,&DAT_003f335c,3,value,value); items[1].active=1; field21c=0; control->FUN_000bc9f0("DynamicControlButtonLabel",0); __security_check_cookie(cookie); }
