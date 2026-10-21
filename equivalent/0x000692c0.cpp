// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 10/10)
// FUN_000692c0 @ 0x000692c0
#include "compat/ptr.h"
struct Curve_692c0 {
 char pad[0x14];
 float a0, a1, b0, b1;
 hulk_freg FUN_000692c0(float t);
};
hulk_freg Curve_692c0::FUN_000692c0(float t) {
 float db = b1-b0;
 float da = a1-a0;
 double b=b0, a=a0;
 if (db >= 0.0f && da >= 0.0f && t >= 0.0f && t <= 1.0f) {
  b=(double)db*t+b0;
  a=(double)da*t+a0;
 }
 if (a <= 0.0) return 0.0f;
 return (float)((b+b)/(a*a));
}
