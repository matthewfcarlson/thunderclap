// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 12/12)
// FUN_00088c30 @ 0x00088c30
struct Target;
struct Vec { unsigned int x,y,z; };
struct Service {
 void FUN_001ce020(void*); void FUN_001cbfe0(void*); void FUN_000b3d80(void*); void FUN_00106430(Target*,void*); void FUN_001af770(); void FUN_000677d0(); void FUN_0002ab40(Target*,void*); void FUN_001e6f10(Target*,void*); void FUN_00080b70(Target*,void*); void FUN_001b5da0(Target*,void*); void FUN_001dbe50(Target*); void FUN_0002ae80(Target*,void*); void FUN_001b6a90(Target*,void*); void FUN_001fc6a0(void*); void FUN_001f7320(Target*,void*); void FUN_001d1160(void*); void FUN_0009bb50(Target*,void*); Vec* FUN_001c39b0(); Vec* FUN_001c39c0(); Vec* FUN_001c39d0(); void FUN_001eda90(Vec,Vec,Vec); void FUN_001c04e0(void*); void FUN_001bc710(void*); Service* FUN_00086320(); float FUN_00085fc0(); void FUN_000d6f30(Target*,float); void FUN_001ed320(Target*,void*); void FUN_000b3d40();
};
extern Service* __cdecl FUN_000678d0();
extern unsigned int __cdecl FUN_00267f00();
extern float __cdecl FUN_00085e60(unsigned int,unsigned int);
extern Service* __cdecl FUN_001d4c90();
extern Service* __cdecl FUN_001c3d90();
extern unsigned char DAT_004dd8e4;
extern float DAT_004dd918;
struct Target {
 unsigned int field0;
 Service *s04,*s08,*s0c,*s10,*s14,*s18,*s1c,*s20,*s24,*s28,*s2c,*s30,*s34,*s38,*s3c,*s40,*s44,*s48,*s4c,*s50,*s54;
 void update(int* kind,void* arg);
};
void Target::update(int* kind,void* arg) {
 if (*kind==6 || *kind==7) { s04->FUN_000b3d40(); return; }
 s2c->FUN_001ce020(arg);
 s30->FUN_001cbfe0(arg);
 s04->FUN_000b3d80(arg);
 s18->FUN_00106430(this,arg);
 s1c->FUN_001af770();
 FUN_000678d0()->FUN_000677d0();
 s20->FUN_0002ab40(this,arg);
 unsigned int start=0;
 if(DAT_004dd8e4) start=FUN_00267f00();
 s0c->FUN_001e6f10(this,arg);
 if(DAT_004dd8e4) {
 unsigned int end=FUN_00267f00();
 if(DAT_004dd8e4) DAT_004dd918=FUN_00085e60(end-start,0);
 }
 s4c->FUN_00080b70(this,arg);
 s10->FUN_001b5da0(this,arg);
 s0c->FUN_001dbe50(this);
 s20->FUN_0002ae80(this,arg);
 s14->FUN_001b6a90(this,arg);
 s28->FUN_001fc6a0(arg);
 s38->FUN_001f7320(this,arg);
 Service* optional=FUN_001d4c90();
 if(optional) optional->FUN_001d1160(arg);
 s08->FUN_0009bb50(this,arg);
 Service* source=FUN_001c3d90();
 Service* destination=s34;
 Vec* a=source->FUN_001c39b0();
 Vec* b=source->FUN_001c39c0();
 Vec* c=source->FUN_001c39d0();
 destination->FUN_001eda90(*c,*b,*a);
 s50->FUN_001c04e0(arg);
 s40->FUN_001bc710(arg);
 Service* consumer=s3c;
 Service* time=s54->FUN_00086320();
 float delta=time->FUN_00085fc0();
 consumer->FUN_000d6f30(this,delta);
 s34->FUN_001ed320(this,arg);
}