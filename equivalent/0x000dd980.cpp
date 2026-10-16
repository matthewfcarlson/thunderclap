// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// ControllerPoller::vfunc_2 @ 0x000dd980
#include "gen/global.h"
#include "decls/data/game/global.h"

struct ControllerPollerBase_dd980 {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
};

void ControllerPoller::vfunc_2() {
 if ((*(volatile int*)&DAT_004de8c0) >= 24) return;
 ((volatile int*)&DAT_004de800)[(*(volatile int*)&DAT_004de8c0) * 2] = 4;
 ((volatile int*)((char*)&DAT_004de800 + 4))[(*(volatile int*)&DAT_004de8c0) * 2] = 8;
 ++(*(volatile int*)&DAT_004de8c0);
 if ((*(volatile int*)&DAT_004de8c0) >= 24) return;
 ((volatile int*)&DAT_004de800)[(*(volatile int*)&DAT_004de8c0) * 2] = 5;
 ((volatile int*)((char*)&DAT_004de800 + 4))[(*(volatile int*)&DAT_004de8c0) * 2] = 10;
 ++(*(volatile int*)&DAT_004de8c0);
 if ((*(volatile int*)&DAT_004de8c0) >= 24) return;
 ((volatile int*)&DAT_004de800)[(*(volatile int*)&DAT_004de8c0) * 2] = 6;
 ((volatile int*)((char*)&DAT_004de800 + 4))[(*(volatile int*)&DAT_004de8c0) * 2] = 11;
 ++(*(volatile int*)&DAT_004de8c0);
 if ((*(volatile int*)&DAT_004de8c0) >= 24) return;
 ((volatile int*)&DAT_004de800)[(*(volatile int*)&DAT_004de8c0) * 2] = 7;
 ((volatile int*)((char*)&DAT_004de800 + 4))[(*(volatile int*)&DAT_004de8c0) * 2] = 9;
 ++(*(volatile int*)&DAT_004de8c0);
 if ((*(volatile int*)&DAT_004de8c0) >= 24) return;
 ((volatile int*)&DAT_004de800)[(*(volatile int*)&DAT_004de8c0) * 2] = 8;
 ((volatile int*)((char*)&DAT_004de800 + 4))[(*(volatile int*)&DAT_004de8c0) * 2] = 12;
 ++(*(volatile int*)&DAT_004de8c0);
 if ((*(volatile int*)&DAT_004de8c0) >= 24) return;
 ((volatile int*)&DAT_004de800)[(*(volatile int*)&DAT_004de8c0) * 2] = 9;
 ((volatile int*)((char*)&DAT_004de800 + 4))[(*(volatile int*)&DAT_004de8c0) * 2] = 13;
 ++(*(volatile int*)&DAT_004de8c0);
}
