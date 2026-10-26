#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern "C" char DAT_00411110[];
struct Ref_12dcf0 {
    virtual void f0();
    virtual void f1();
};
extern void* Alloc(hulk_uintptr);
struct Memory_12dcf0 {
    void Init();
};

hulk_intptr hulkfight::PostEvent_StringTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr __p2) { Ref_12dcf0 * param = (Ref_12dcf0 *)__p2;

    char* p = (char*)Alloc(0x24);
    if (p) {
        ((Memory_12dcf0*)p)->Init();
        *(void**)(p + 0x1c) = this;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00411110);
        *(unsigned int*)(p + 0x20) = 0;
        if (param)
            param->f0();
        Ref_12dcf0* old = *(Ref_12dcf0**)(p + 0x20);
        if (old)
            old->f1();
        *(Ref_12dcf0**)(p + 0x20) = param;
        return (hulk_intptr)(p);
    }
    return (int)(0);
}
