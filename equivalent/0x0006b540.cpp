// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 10/10)
// FUN_0006b540 @ 0x0006b540
#include "compat/ptr.h"
struct Object {
 char pad[0x14];
 float x0,x1,y0,y1;
 float FUN_00069390(float x, float y);
 hulk_freg FUN_0006b540(float t);
};
hulk_freg Object::FUN_0006b540(float t) {
 float dy = y1-y0;
 float dx = x1-x0;
 if (dy >= 0.0f && dx >= 0.0f && t >= 0.0f && t <= 1.0f)
  return FUN_00069390(dx*t+x0, dy*t+y0);
 if (x0 <= 0.0f) return 0.0f;
 return (y0/x0)*2.0f;
}