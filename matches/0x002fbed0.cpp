#include "compat/ptr.h"
extern "C" char DAT_004317dc[];
class Part_2fbed0 {
  public:
    void Init();
};
class CollisionOBB_2fbed0 {
  public:
    virtual void v();
    char pad[0x38];
    Part_2fbed0 p1;
    char pad2[0x3f];
    Part_2fbed0 p2;
    void Base();
    void Build(int, int, int, int, int);
    CollisionOBB_2fbed0* Target(int, int, int, int, int);
};
CollisionOBB_2fbed0* CollisionOBB_2fbed0::Target(int a, int b, int c, int d, int e) {
    Base();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004317dc);
    p1.Init();
    p2.Init();
    Build(a, b, c, d, e);
    return this;
}
