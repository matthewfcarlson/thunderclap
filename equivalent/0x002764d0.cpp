// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002764d0 @ 0x002764d0
#include "compat/ptr.h"
#include "decls/data/records.h"

// core::File's constructor (records.h CoreFile): the bases' vftables, then its own; a reference to the drive (slot
// 0), the name (0x00271cf0 normalizes it, else a plain copy), and with `open` set an open request (0x00274f20) queued
// on the drive (0x00272b60)
struct Provider_2764d0 {
 virtual void slot0();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 int FUN_00272b60(void*, int, int);
};
struct Embedded_2764d0 { void FUN_00277c00(); };
extern "C" int* FUN_002705f0();
int __cdecl thunk_FUN_00271cf0(char*, const char*, int);
extern "C" char* __cdecl _strncpy(char*, const char*, unsigned);
void* __cdecl FUN_00273560(unsigned);
struct FileOpenRequest_2764d0 { void* FUN_00274f20(void*, int, unsigned char); };
extern "C" char DAT_0042b850[];
extern "C" char DAT_0042bd30[];
extern "C" char DAT_0042bd3c[];
namespace core {
struct File_2764d0 : CoreFile {
 File_2764d0(Provider_2764d0*,const char*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned char);
};
File_2764d0::File_2764d0(Provider_2764d0* p,const char* name,unsigned a3,unsigned a4,unsigned a5,unsigned a6,unsigned a7,unsigned a8,unsigned char a9) {
 vftableMutable=DAT_0042b850;
 vftable=DAT_0042bd3c; vftableMutable=DAT_0042bd30;
 refs=1; provider=p; key=a5; field14=0; field18=0; flag1c=0; flag1d=(unsigned char)a3;
 field120=0; field124=0; field128=0;
 ((Embedded_2764d0*)&view)->FUN_00277c00();
 field160=0; field164=0x800;
 FUN_002705f0();
 ((Provider_2764d0*)provider)->slot0();
 if(thunk_FUN_00271cf0(filename,name,0x100)<0) { _strncpy(filename,name,0x100); filename[0x100]=0; }
 ((Provider_2764d0*)provider)->slot6();
 if(a9) {
 FileOpenRequest_2764d0* h=(FileOpenRequest_2764d0*)FUN_00273560(0x14);
 void* result=0;
 if(h) result=h->FUN_00274f20(this,(int)a4,(unsigned char)a3);
 ((Provider_2764d0*)provider)->FUN_00272b60(result,(int)key,0);
 }
}
}
