#include "compat/ptr.h"
class Sub_266790 {
  public:
    int f();
    int g();
};
class Obj_266790 {
    char pad0[0x14];
    int mode;
    char pad18[4];
    Sub_266790* sub;

  public:
    hulk_freg run();
};
extern const float one;
extern const float zero_266790;
extern const float fix;
hulk_freg Obj_266790::run() {
    switch (mode) {
    case 3:
        return 1.0f;
    case 2:
        if (sub)
            return (float)(unsigned int)sub->f() / (float)(unsigned int)sub->g();
        return 0.0f;
    default:
        return 0.0f;
    }
}