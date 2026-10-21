#include "compat/ptr.h"
class Obj_69370 {
  public:
    char pad[0x30];
    int a;
    int b;
    int c;
    int d;
    hulk_freg f(int);
};
float callee(int, int, int, int, int);
hulk_freg Obj_69370::f(int x) {
    return callee(b, a, d, c, x);
}