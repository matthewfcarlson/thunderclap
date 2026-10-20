#include "compat/ptr.h"
class Sub_194fd0 {
  public:
    void Init();
};
class MissilePunchTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual MissilePunchTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14];
    Sub_194fd0 sub;
    void Setup();
};
extern int missileVftable;
extern void Cleanup(MissilePunchTrack*);
MissilePunchTrack* MissilePunchTrack::vfunc_5(int flag) {
    *(hulk_intptr*)this = (hulk_intptr)&missileVftable;
    sub.Init();
    Setup();
    if (flag & 1)
        Cleanup(this);
    return this;
}