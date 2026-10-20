#include "compat/ptr.h"
extern "C" char DAT_003fa214[];
class Base_5da90 {
  public:
    void Done();
};
class TypeA {
  public:
    void Done();
};
class TypeB {
  public:
    void Done();
};
class CCollisionTrack {
  public:
    virtual void Dummy();
    char pad[0x14];
    char a18[0x34];
    char a4c[0xc];
    char a58[0x10];
    char a68[8];
    char a70[4];
    void Fini();
};
void CCollisionTrack::Fini() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003fa214);
    ((TypeA*)a70)->Done();
    ((TypeA*)a68)->Done();
    ((TypeB*)a58)->Done();
    ((TypeB*)a4c)->Done();
    ((TypeA*)a18)->Done();
    ((Base_5da90*)this)->Done();
}
