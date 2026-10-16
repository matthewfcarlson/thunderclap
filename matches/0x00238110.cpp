#include "gen/fight.h"

extern "C" char DAT_00428100[];
typedef unsigned int u32_238110;
void* __cdecl operator_new(unsigned int);
struct Obj_238110 {
    void Ctor();
};
struct Sub1_238110 {
    void Init1();
};
struct Sub2_238110 {
    void Init2();
};

template <> void* fight::TrackFactoryTemplate<fight::SequenceTrack>::vfunc_5() {
    Obj_238110* p = (Obj_238110*)operator_new(0x20);
    if (p) {
        p->Ctor();
        Sub1_238110* s1 = (Sub1_238110*)((char*)p + 0xc);
        *(u32_238110*)p = ((int)DAT_00428100);
        s1->Init1();
        Sub2_238110* s2 = (Sub2_238110*)((char*)p + 0x1c);
        *(u32_238110*)((char*)p + 0x18) = 1;
        s2->Init2();
        *(u32_238110*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
