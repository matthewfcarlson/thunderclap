#include "decls/data/engine/audio.h"
// data: gBss_24fee0 = DAT_004e68f8

class SeqEventContainer {
  public:
    char pad[0x14];
};
class SeqEventCondition : public SeqEventContainer {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventCondition* vfunc_4(unsigned char);
    virtual void v5();
};
class A_24fee0 {
  public:
    void f();
};
class SeqEventCondition_24fee0 {
  public:
    void f();
};
void __cdecl f47550(void*, SeqEventCondition*);
SeqEventCondition* SeqEventCondition::vfunc_4(unsigned char flag) {
    ((A_24fee0*)((char*)this + 0x14))->f();
    ((SeqEventCondition_24fee0*)this)->f();
    if (flag & 1)
        f47550(((char*)&DAT_004e68f8), this);
    return this;
}