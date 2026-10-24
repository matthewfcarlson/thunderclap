#include "gen/choreo2.h"

#include "compat/ptr.h"
extern "C" char DAT_004272b8[];
typedef unsigned int u32_222620;
typedef unsigned char u8;
struct Arg_222620 {
    virtual void F();
};
struct Sub_222620 {
    char x[4];
    void Init();
};
struct Puppet_nv_222620 {
    void BaseInit();
};

choreo2::Puppet* choreo2::Puppet::FUN_00222620(void* __p0) { Arg_222620 * param = (Arg_222620 *)__p0;

    ((Puppet_nv_222620*)this)->BaseInit();
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004272b8);
    ((Sub_222620*)((char*)this + 0x10))->Init();
    *(u32_222620*)((char*)this + 0x68) = 0;
    *(u8*)((char*)this + 0x2ec) = 0;
    *(Arg_222620**)((char*)this + 0x64) = param;
    param->F();
    return (choreo2::Puppet*)(this);
}
