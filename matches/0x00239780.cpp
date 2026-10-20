#include "compat/ptr.h"
extern "C" char DAT_00428418[];
class ExecuteTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ExecuteTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x2c];
};
class A_239780 {
  public:
    void First();
};
class B_239780 {
  public:
    void Second();
};
class C_239780 {
  public:
    void Third();
};
extern void __cdecl thunk_FUN_00267090(ExecuteTrack*);
ExecuteTrack* ExecuteTrack::vfunc_5(int flags) {
    ExecuteTrack* p = this;
    *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00428418);
    ((A_239780*)((char*)p + 0x24))->First();
    ((B_239780*)((char*)p + 0x14))->Second();
    ((C_239780*)p)->Third();
    if (flags & 1)
        thunk_FUN_00267090(p);
    return p;
}