#include "gen/owners.h"
class Sub_2f5d20 {
  public:
    char pad[0x34];
};
class PhysicsObject {
  public:
    virtual void dummy();
    char pad[0x114 - 4];
    Sub_2f5d20 sub;
    unsigned char flag;
    unsigned long a, b, c;
    bool vfunc_25(unsigned long* out, unsigned long arg, unsigned long unused);
};
bool PhysicsObject::vfunc_25(unsigned long* out, unsigned long arg, unsigned long unused) {
    if (flag)
        return false;
    out[0] = a;
    out[1] = b;
    out[2] = c;
    ((owners::Transform_2fd020 *)&sub)->FUN_002fd020((float *)((char*)this + 0x158), (float *)(hulk_uintptr)(unsigned long)arg);
    return true;
}
