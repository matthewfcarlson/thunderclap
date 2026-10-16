#include "gen/fight.h"

extern "C" char DAT_00413738[];
void* operator_new(unsigned int);
typedef unsigned int u32_14c220;

struct Base1_14c220 {
    void Init1();
};
struct Sub1_14c220 {
    void Init2();
};
struct Sub2_14c220 {
    void Init3();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_5() {
    char* p = (char*)operator_new(0x28);
    if (p) {
        ((Base1_14c220*)p)->Init1();
        *(u32_14c220*)(p) = ((int)DAT_00413738);
        *(u32_14c220*)(p + 0xc) = 0;
        *(u32_14c220*)(p + 0x10) = 0xbf800000;
        ((Sub1_14c220*)(p + 0x14))->Init2();
        *(u32_14c220*)(p + 0x20) = 0xfffffc18;
        ((Sub2_14c220*)(p + 0x24))->Init3();
        return (void*)(p);
    }
    return (void*)(0);
}
