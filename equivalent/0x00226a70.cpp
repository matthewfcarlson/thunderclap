// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 6/8, incomplete)
// FUN_00226a70 @ 0x00226a70
#include "compat/ptr.h"
extern float __cdecl FUN_0004af40(float low, float high, float value);
extern double __cdecl __floor_default(double value);
struct Curve_226a70 {
 char pad[0x2c];
 unsigned int count;
 float FUN_00226960(unsigned int index, float angle);
 hulk_freg FUN_00226a70(float position, float angle);
};
hulk_freg Curve_226a70::FUN_00226a70(float position, float angle) {
 angle = FUN_0004af40(0.0f, 6.283185307179586f, angle);
 double base = __floor_default(position);
 if (base < 0.0f) return 0.0f;
 unsigned int index = (unsigned int)base;
 unsigned int last = count - 1;
 if (index >= last) {
  double value = FUN_00226960(last, angle);
  double lastValue = (double)(int)last;
  if ((int)last < 0) lastValue += 4294967296.0f;
  return (hulk_freg)(value * ((double)position - lastValue));
 }
 float first = FUN_00226960(index, angle);
 double second = FUN_00226960(index + 1, angle);
 double indexValue = (double)(int)index;
 if ((int)index < 0) indexValue += 4294967296.0f;
 return (hulk_freg)((second - first) * ((double)position - indexValue) + first);
}
