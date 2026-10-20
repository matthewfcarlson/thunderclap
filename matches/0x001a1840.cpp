#include "compat/ptr.h"
typedef unsigned char u8_1a1840;
extern int LuaTrack_vftable;
struct LuaTrack {
    char pad[0x10];
    int m14;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual LuaTrack* vfunc_5(u8_1a1840 param);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    void helper();
};
void ReleaseA(void* p);
void ReleaseB(void* p);
LuaTrack* LuaTrack::vfunc_5(u8_1a1840 param) {
    *(hulk_intptr*)this = (hulk_intptr)&LuaTrack_vftable;
    ReleaseA((void*)m14);
    helper();
    if (param & 1)
        ReleaseB(this);
    return this;
}
