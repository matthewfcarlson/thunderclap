// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// ControllerPoller::vfunc_2 @ 0x000dd980
struct ControllerPollerBase {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
};
struct ControllerPoller : ControllerPollerBase { virtual void vfunc_2(); };
extern volatile int DAT_004de800[];
extern volatile int DAT_004de804[];
extern volatile int DAT_004de8c0;
void ControllerPoller::vfunc_2() {
 if (DAT_004de8c0 >= 24) return;
 DAT_004de800[DAT_004de8c0 * 2] = 4;
 DAT_004de804[DAT_004de8c0 * 2] = 8;
 ++DAT_004de8c0;
 if (DAT_004de8c0 >= 24) return;
 DAT_004de800[DAT_004de8c0 * 2] = 5;
 DAT_004de804[DAT_004de8c0 * 2] = 10;
 ++DAT_004de8c0;
 if (DAT_004de8c0 >= 24) return;
 DAT_004de800[DAT_004de8c0 * 2] = 6;
 DAT_004de804[DAT_004de8c0 * 2] = 11;
 ++DAT_004de8c0;
 if (DAT_004de8c0 >= 24) return;
 DAT_004de800[DAT_004de8c0 * 2] = 7;
 DAT_004de804[DAT_004de8c0 * 2] = 9;
 ++DAT_004de8c0;
 if (DAT_004de8c0 >= 24) return;
 DAT_004de800[DAT_004de8c0 * 2] = 8;
 DAT_004de804[DAT_004de8c0 * 2] = 12;
 ++DAT_004de8c0;
 if (DAT_004de8c0 >= 24) return;
 DAT_004de800[DAT_004de8c0 * 2] = 9;
 DAT_004de804[DAT_004de8c0 * 2] = 13;
 ++DAT_004de8c0;
}
