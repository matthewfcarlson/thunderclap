// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022add0 @ 0x0022add0
#include "gen/owners.h"
struct Object {  void FUN_0022add0(float *out); };
void Object::FUN_0022add0(float *out) {
    float x = ((owners::RandomGen_143100 *)this)->FUN_00143100();
    float y = ((owners::RandomGen_143100 *)this)->FUN_00143100();
    float z = ((owners::RandomGen_143100 *)this)->FUN_00143100();
    out[0] = x;
    out[1] = y;
    out[2] = z;
}