#include "compat/ptr.h"
extern "C" char DAT_004282fc[];
void __cdecl thunk_FUN_00267090(void* p);
void __cdecl thunk_FUN_00267090_b(void* p);
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    void FUN_00236d60();
    char pad[8];
    int a;
    int b;
};
class PrintTrack : public Track {
  public:
    virtual PrintTrack* vfunc_5(unsigned char);
};
PrintTrack* PrintTrack::vfunc_5(unsigned char p) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004282fc);
    thunk_FUN_00267090((void*)(*(hulk_intptr*)((char*)this + 0x10)));
    thunk_FUN_00267090((void*)(*(hulk_intptr*)((char*)this + 0x14)));
    FUN_00236d60();
    if (p & 1)
        thunk_FUN_00267090_b((void*)this);
    return this;
}
