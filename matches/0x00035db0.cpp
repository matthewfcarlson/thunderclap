extern "C" unsigned char gState;
extern "C" unsigned char __cdecl FUN_00035db0(unsigned char value) {
    unsigned char old = gState;
    gState = value;
    return old;
}