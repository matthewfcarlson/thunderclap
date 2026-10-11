// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002764d0 @ 0x002764d0
namespace core {
struct Primary { virtual void file_slot(); };
struct IMutable { virtual void mutable_slot(); };
}
struct Provider {
 virtual void slot0();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 void FUN_00272b60(void*, unsigned, int);
};
struct Embedded { char data[0x34]; void FUN_00277c00(); };
void __cdecl FUN_002705f0();
int __cdecl thunk_FUN_00271cf0(char*, const char*, int);
char* __cdecl _strncpy(char*, const char*, unsigned);
void* __cdecl FUN_00273560(unsigned);
namespace core { struct File; }
struct Helper { void* FUN_00274f20(core::File*, unsigned, unsigned); };
namespace core {
struct File : Primary, IMutable {
 virtual void file_slot(); virtual void mutable_slot();
 unsigned refs;
 Provider* provider;
 unsigned key;
 unsigned field14, field18;
 unsigned char flag1c, flag1d;
 char filename[0x101];
 char pad11f;
 unsigned field120, field124, field128;
 Embedded embedded;
 unsigned char field160;
 char pad161[3];
 unsigned field164;
 File(Provider*,const char*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned char);
};
File::File(Provider* p,const char* name,unsigned a3,unsigned a4,unsigned a5,unsigned a6,unsigned a7,unsigned a8,unsigned char a9) {
 refs=1; provider=p; key=a5; field14=0; field18=0; flag1c=0; flag1d=(unsigned char)a3;
 field120=0; field124=0; field128=0;
 embedded.FUN_00277c00();
 field160=0; field164=0x800;
 FUN_002705f0();
 provider->slot0();
 if(thunk_FUN_00271cf0(filename,name,0x100)<0) { _strncpy(filename,name,0x100); filename[0x100]=0; }
 provider->slot6();
 if(a9) {
 Helper* h=(Helper*)FUN_00273560(0x14);
 void* result=0;
 if(h) result=h->FUN_00274f20(this,a4,a3);
 provider->FUN_00272b60(result,key,0);
 }
}
}