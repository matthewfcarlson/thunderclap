// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CPathAgent::vfunc_9 @ 0x00104b50
struct Vec3_104b50 { float x,y,z; };
struct Location { void FUN_00059a50(Vec3_104b50*); };
struct Result_104b50 { char pad[16]; Location* location; };
struct Provider_104b50 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual Result_104b50* slot6(); };
struct Allocation_104b50 { void* first; char pad[8]; void* second; };
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
struct CPathAgent {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 char pad04[4]; int state; char pad0c[76]; Provider_104b50* provider; int f5c; int f60; Allocation_104b50* allocation; int f68; int f6c; int f70; int f74; int f78; char pad7c[12]; unsigned char f88,f89; char pad8a[2]; float f8c; unsigned char f90; char pad91[3]; float f94,f98; int f9c; Vec3_104b50 position; float fac; int fb0,fb4,fb8; char padbc[28]; int fd8,fdc,fe0,fe4,fe8,fec,ff0,ff4; float ff8;
};
void CPathAgent::vfunc_9() {
 Allocation_104b50* old=allocation;
 state=0; f5c=0; f6c=0;
 if(old) { FUN_0008d340(old->first); FUN_0008d340(old->second); FUN_0008d330(old); allocation=0; }
 f68=0; f70=0; f74=0; f78=0;
 f88=0; f89=1; f8c=1.0f; f90=0; f94=1.0f; f98=1.0f; f9c=0;
 fb8=0; fb4=0; fb0=0; fac=2.5f;
 Result_104b50* result=0;
 if(provider) result=provider->slot6();
 if(result) result->location->FUN_00059a50(&position);
 else { position.x=-1.0f; position.y=-1.0f; position.z=-1.0f; }
 fe0=0; fdc=0; fd8=0; fe4=0; ff0=0; fec=0; fe8=0; ff4=0; ff8=999.0f;
}
