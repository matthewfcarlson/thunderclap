#include "compat/ptr.h"
extern "C" char DAT_0041941c[];
typedef unsigned char u8_1832e0;
extern void __cdecl cleanup(void*);
class Sub_1832e0 {
  public:
    void Init();
};
namespace hulkfight { namespace motion { class BallAndChainReturnTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual BallAndChainReturnTrack* vfunc_5(u8_1832e0);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    void BaseInit();
    char pad[0x60 - 4];
}; }}
hulkfight::motion::BallAndChainReturnTrack* hulkfight::motion::BallAndChainReturnTrack::vfunc_5(u8_1832e0 flag) {
    Sub_1832e0* a = (Sub_1832e0*)((char*)this + 0x60);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0041941c);
    a->Init();
    ((Sub_1832e0*)((char*)this + 0x48))->Init();
    this->BaseInit();
    if (flag & 1)
        cleanup(this);
    return this;
}
