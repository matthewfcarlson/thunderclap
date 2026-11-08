// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002733c0 @ 0x002733c0
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"

extern "C" char DAT_003f6098[], DAT_0042afa8[], DAT_0042b85c[], DAT_0042b8e0[], DAT_0042b8f0[], DAT_0042b8f8[];
extern "C" int* FUN_002705f0();
extern "C" void __cdecl FUN_0026d860(hulk_uintptr*, int);
extern "C" int __cdecl FUN_002731d0(hulk_intptr);
// the game passes a sixth argument (the heap id) that 0x0026dce0 does not read
extern "C" void __cdecl FUN_0026dce0(CoreThread*, int (__cdecl*)(hulk_intptr), hulk_intptr, int, unsigned long, hulk_uintptr);
// core::DriveThread (records.h CoreDriveThread): the bases' vftables, then its own; the worker thread runs 0x002731d0
struct DriveThread_2733c0 : CoreDriveThread {
 DriveThread_2733c0* FUN_002733c0(hulk_uintptr, hulk_uintptr);
};
DriveThread_2733c0* DriveThread_2733c0::FUN_002733c0(hulk_uintptr arg1, hulk_uintptr arg2) {
 vftable=DAT_003f6098; vftableObject=DAT_0042afa8; heap=DAT_004cdbb0;
 FUN_002705f0();
 vftableMutable=DAT_0042b85c; refs=1;
 vftable=DAT_0042b8f8; vftableObject=DAT_0042b8f0; vftableMutable=DAT_0042b8e0;
 lock=(void*)arg1; stopped=0; requeue=0; count=0; unknown90=0;
 FUN_002705f0();
 heads[0]=0; tails[0]=0; heads[1]=0; tails[1]=0; heads[2]=0; tails[2]=0;
 FUN_0026d860(&ready,0);
 FUN_0026d860(&done,0);
 FUN_0026dce0(&worker,FUN_002731d0,(hulk_intptr)this,4,0x2000,arg2);
 return this;
}
