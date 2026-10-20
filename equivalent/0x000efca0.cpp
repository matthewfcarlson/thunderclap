// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 24/24)
// FUN_000efca0 @ 0x000efca0
#include "compat/ptr.h"
void* __cdecl FUN_0008d690(hulk_uintptr);
struct Manager_efca0;
struct FEMenuBase {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual const char* v8();
 virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(int);
 char pad[0x98c]; int field990; char tail[0x230];
 void FUN_000ef180(Manager_efca0*,const char*);
};
struct Manager_efca0 { char pad[0x20c]; FEMenuBase* menus[256]; FEMenuBase* FUN_000efca0(const char*,int); };
FEMenuBase* Manager_efca0::FUN_000efca0(const char* name,int arg) {
 FEMenuBase* found=0;
 for(int i=0;i<256;++i) {
  if(menus[i]) {
   const char* s=menus[i]->v8(); const char* p=name;
   while(*p==*s && *p) { ++p; ++s; }
   if(*p==*s) { found=menus[i]; break; }
  }
 }
 if(found) return found;
 int slot=0; while(slot<256 && menus[slot]) ++slot;
 if(slot==256) return found;
 found=(FEMenuBase*)FUN_0008d690(0xbc4);
 if(found) {
 found->FUN_000ef180(this,name);
 found->FEMenuBase::FEMenuBase();
 found->field990=0;
 }
 menus[slot]=found;
 if(found) found->v54(arg);
 return found;
}