#include "compat/ptr.h"
#include "decls/data/engine/om.h"

extern "C" char DAT_0042aa40[];
struct Pair_25fa00 {
    int a;
    int b;
};
struct MetaType {
    hulk_intptr vptr;
    char pad04[0x10];
    int* m14;
    int* m18;
    int* m1c;
    int* m20;
    int m24;
    int pad28;
    Pair_25fa00 key;
    MetaType* Init(int, int);
};
extern void Register(int*, MetaType*, Pair_25fa00*);
MetaType* MetaType::Init(int a, int b) {
    int* p = (int*)((char*)this + 0x18);
    vptr = ((hulk_intptr)DAT_0042aa40);
    *p = (hulk_intptr)p;
    m1c = p;
    m20 = p;
    m14 = p;
    m24 = 0;
    Pair_25fa00* k = &key;
    k->a = a;
    key.b = b;
    if (*(int*)((hulk_intptr)DAT_004e79cc) == 0) {
        *(hulk_intptr*)((hulk_intptr)DAT_004e79bc) = ((hulk_intptr)DAT_004e79bc);
        *(hulk_intptr*)((hulk_intptr)DAT_004e79c0) = ((hulk_intptr)DAT_004e79bc);
        *(hulk_intptr*)((hulk_intptr)DAT_004e79c4) = ((hulk_intptr)DAT_004e79bc);
        *(int*)((hulk_intptr)DAT_004e79c8) = 0;
        *(hulk_intptr*)((hulk_intptr)DAT_004e79b8) = ((hulk_intptr)DAT_004e79bc);
    }
    Register(*(int**)((hulk_intptr)((char*)&DAT_004cd360)), this, k);
    ++*(int*)((hulk_intptr)DAT_004e79cc);
    return this;
}