// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002733c0 @ 0x002733c0
#include "decls/data/engine/core.h"

extern const unsigned int DAT_003f6098[], DAT_0042afa8[], DAT_0042b85c[], DAT_0042b8e0[], DAT_0042b8f0[], DAT_0042b8f8[];
extern void __cdecl FUN_002705f0();
extern void __cdecl FUN_0026d860(void*, int);
extern void __cdecl FUN_002731d0();
extern void __cdecl FUN_0026dce0(void*, void (__cdecl*)(), void*, int, int, unsigned int);
struct DriveThread {
 const unsigned int* refTable;
 const unsigned int* objectTable;
 unsigned int objectValue;
 const unsigned int* safeTable;
 unsigned int count;
 unsigned int owner;
 char thread[0x4c];
 unsigned char flag;
 char pad65[3];
 unsigned int a68,a6c,a70,a74,a78,a7c,a80,a84;
 unsigned char flag88;
 char pad89[3];
 unsigned int a8c,a90;
 DriveThread* FUN_002733c0(unsigned int, unsigned int);
};
DriveThread* DriveThread::FUN_002733c0(unsigned int arg1, unsigned int arg2) {
 refTable=DAT_003f6098; objectTable=DAT_0042afa8; objectValue=(*(unsigned int*)&DAT_004cdbb0);
 FUN_002705f0();
 safeTable=DAT_0042b85c; count=1;
 refTable=DAT_0042b8f8; objectTable=DAT_0042b8f0; safeTable=DAT_0042b8e0;
 owner=arg1; flag=0; flag88=0; a8c=0; a90=0;
 FUN_002705f0();
 a6c=0; a78=0; a70=0; a7c=0; a74=0; a80=0;
 FUN_0026d860(&a68,0);
 FUN_0026d860(&a84,0);
 FUN_0026dce0(thread,FUN_002731d0,this,4,0x2000,arg2);
 return this;
}