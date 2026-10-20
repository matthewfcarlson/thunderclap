#include "compat/ptr.h"
extern "C" char DAT_0041c5f0[];
struct Helper_1a5c50 {
    void Init();
};
struct TrackBase_1a5c50 {
    void InitTrack();
};
class EffectTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual EffectTrack* vfunc_5(unsigned char flag);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x58 - 4];
};
void __cdecl Destroy(EffectTrack*);
EffectTrack* EffectTrack::vfunc_5(unsigned char flag) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0041c5f0);
    ((Helper_1a5c50*)((char*)this + 0x58))->Init();
    ((Helper_1a5c50*)((char*)this + 0x30))->Init();
    ((Helper_1a5c50*)((char*)this + 0x20))->Init();
    ((Helper_1a5c50*)((char*)this + 0x18))->Init();
    ((TrackBase_1a5c50*)this)->InitTrack();
    if (flag & 1)
        Destroy(this);
    return this;
}
