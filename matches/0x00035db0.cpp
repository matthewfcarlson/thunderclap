extern "C" unsigned char gState_35db0;
extern "C" unsigned char __cdecl FUN_00035db0(unsigned char value) {
    unsigned char old = gState_35db0;
    gState_35db0 = value;
    return old;
}