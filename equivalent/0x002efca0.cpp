// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 16/16)
// FUN_002efca0 @ 0x002efca0
#include "decls/address.h"
struct BaseInput { void FUN_00306380(); };
struct Text_2efca0 { void FUN_0027b040(const char*); };
struct Observer_2efca0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); };
struct CollisionObject_2efca0;
struct Result_2efca0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void attach(CollisionObject_2efca0*); Result_2efca0* FUN_002ef7f0(int); };
struct CollisionObject_2efca0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual CollisionObject_2efca0* attach(Result_2efca0*); char pad4[4]; Text_2efca0 text; char pad9[15]; Result_2efca0* child; char pad1c[4]; Observer_2efca0* observer; char pad24[44]; unsigned char flag50; char pad51[23]; unsigned char flag68; unsigned char flag69; char pad6a[2]; int field6c; char pad70[16]; CollisionObject_2efca0* FUN_00304f50(BaseInput*); void FUN_00304740(int); };
extern void* __cdecl FUN_00263ea0(unsigned int);
extern void* __cdecl FUN_0008d690(unsigned int);
extern int __cdecl FUN_002f2750(__int64);
Result_2efca0* __cdecl target(BaseInput* input, const char* name) {
 input->FUN_00306380();
 CollisionObject_2efca0* n = (CollisionObject_2efca0*)FUN_00263ea0(128);
 if(n) n=n->FUN_00304f50(input);
 n->field6c=0; n->flag50=0;
 n->text.FUN_0027b040(name ? name : "Not baptized yet");
 n->FUN_00304740(FUN_002f2750(FUN_0027b020("")));
 Result_2efca0* r=(Result_2efca0*)FUN_0008d690(136);
 if(r) r=r->FUN_002ef7f0(0);
 if(!r) return 0;
 bool replaced=false;
 if(n->child) { n=n->attach(r); replaced=true; } else n->child=r;
 r->attach(n);
 if(!replaced) { if(n->flag68 || n->flag69) n->observer->v10(); n->observer->v8(); }
 return r;
}