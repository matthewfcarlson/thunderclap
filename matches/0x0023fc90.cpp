#include "decls/data/engine/audio.h"
// data: gThing_23fc90 = DAT_004cc02c

struct Obj_23fc90 {
    void* mPtr;
    short mB;
    short pad;
    short mC;
    void helper(int, int, int, int);
    Obj_23fc90* fn(int, int, int);
};
Obj_23fc90* Obj_23fc90::fn(int a, int b, int c) {
    if (a == 0) {
        mPtr = (*(void**)&DAT_004cc02c);
        short* p = (short*)((char*)(*(void**)&DAT_004cc02c) - 4);
        ++*p;
        mC = 0;
        mB = 2;
    } else
        helper(a, b, b, c);
    return this;
}