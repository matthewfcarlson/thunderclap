#include "compat/ptr.h"
extern "C" char DAT_003fa2c0[];
typedef unsigned char BYTE;
struct SubObj_5e1a0 {
    void f();
};
void destroy(void* p);
struct CStunAnimationTrack {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual CStunAnimationTrack* vfunc_5(BYTE);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    void core();
    char pad[0x30 - 4];
};
CStunAnimationTrack* CStunAnimationTrack::vfunc_5(BYTE param) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003fa2c0);
    ((SubObj_5e1a0*)((char*)this + 0x30))->f();
    ((SubObj_5e1a0*)((char*)this + 0x10))->f();
    this->core();
    if (param & 1)
        destroy(this);
    return this;
}
