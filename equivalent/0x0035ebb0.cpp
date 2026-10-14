// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0035ebb0 @ 0x0035ebb0
// Static init: hash the eight door/switch state names.
extern unsigned __int64 FUN_0027afb0(const char *name);
unsigned __int64 DAT_004e2560;
unsigned __int64 DAT_004e2568;
unsigned __int64 DAT_004e2570;
unsigned __int64 DAT_004e2578;
unsigned __int64 DAT_004e2580;
unsigned __int64 DAT_004e2588;
unsigned __int64 DAT_004e2590;
unsigned __int64 DAT_004e2598;
void FUN_0035ebb0() {
    DAT_004e2560 = FUN_0027afb0("clean");
    DAT_004e2568 = FUN_0027afb0("opening");
    DAT_004e2570 = FUN_0027afb0("open");
    DAT_004e2578 = FUN_0027afb0("closing");
    DAT_004e2580 = FUN_0027afb0("closed");
    DAT_004e2588 = FUN_0027afb0("on");
    DAT_004e2590 = FUN_0027afb0("off");
    DAT_004e2598 = FUN_0027afb0("destroyed");
}
