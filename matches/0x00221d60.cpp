#include "gen/owners.h"
extern "C" void _ReadWriteBarrier();
class Obj_221d60;
class Elem_221d60 {
  public:
};
class Obj_221d60 {
  public:
    void Fn(Obj_221d60*, float);
    char pad0[0x30];
    float x, y, z;
    char pad3c[4];
    Elem_221d60 elem;
    char pad44[0xc];
    int state;
};
void Obj_221d60::Fn(Obj_221d60* other, float t) {
    x = (other->x - x) * t + x;
    y = (other->y - y) * t + y;
    z = (other->z - z) * t + z;

    _ReadWriteBarrier();
    int s = *(volatile int*)&state;
    if (s == 2) {
        ((owners::Quat_22b370 *)&elem)->FUN_0022b370((const float *)(Obj_221d60 *)this);
        state = 0;
    }
    if (other->state == 2) {
        ((owners::Quat_22b370 *)&(other->elem))->FUN_0022b370((const float *)(Obj_221d60 *)other);
        other->state = 0;
    }
    ((owners::Quaternion_22b750 *)&elem)->FUN_0022b750((const owners::Quaternion_22b750 *)(Elem_221d60 *)(&elem), (const owners::Quaternion_22b750 *)(Elem_221d60 *)(&other->elem), t);
    state = 1;
}
