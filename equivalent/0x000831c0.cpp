// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_000831c0 @ 0x000831c0
#include "decls/address.h"
struct Handle_831c0 { void FUN_0027b040(unsigned); };
struct Resource_831c0 {
 virtual void slot0(); virtual void slot1();
 char pad[0x144]; unsigned mode;
 Resource_831c0* FUN_00287860();
 void FUN_00284ad0(unsigned);
 void FUN_00288080(unsigned);
};
struct Source_831c0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual unsigned s11(); };
struct Entry_831c0 { char pad[0x9c]; Source_831c0* source; };
struct Manager_831c0 { bool FUN_001dd800(unsigned); Entry_831c0* FUN_001dc0d0(unsigned); };
struct World { char pad[12]; Manager_831c0* manager; };
void* __cdecl FUN_00263ea0(unsigned);
struct FUN_0027b070 { FUN_0027b070(); virtual void v0(); };
struct CCow : FUN_0027b070 {
 unsigned field4; Handle_831c0 handle; unsigned fieldC;
 unsigned id, value, type;
 unsigned char flag1,flag2; char pad1[2];
 unsigned f20,f24,f28,f2c,f30,f34,f38;
 Resource_831c0* resource;
 unsigned f40,f44,f48;
 virtual void v0();
 CCow(unsigned h,unsigned i,unsigned v,unsigned a,unsigned b);
};
CCow::CCow(unsigned h,unsigned i,unsigned v,unsigned a,unsigned b) {
 id=i; value=v; type=9; flag1=0; flag2=0;
 f20=f24=f28=f2c=f30=f34=f38=0; resource=0; f40=f44=f48=0;
 handle.FUN_0027b040(h);
 Resource_831c0* p=(Resource_831c0*)FUN_00263ea0(0x150);
 if(p) p=p->FUN_00287860();
 if(p) p->slot0();
 if(resource) resource->slot1();
 resource=p;
 p->FUN_00284ad0(0);
 resource->mode=3;
 Manager_831c0* m=DAT_004dd700->manager;
 if(m->FUN_001dd800(id)) {
 Entry_831c0* e=m->FUN_001dc0d0(id);
 unsigned x=e->source->s11();
 resource->FUN_00288080(x);
 }
}