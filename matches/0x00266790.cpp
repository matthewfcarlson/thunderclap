#include "decls/data/engine/pure3d/scenegraph.h"
// data: one = DAT_004c9f38

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
extern const float zero_266790;
extern const float fix;
hulk_freg Obj_266790::run() {
    switch (mode) {
    case 3:
        return 1.0f;
    case 2:
        if (sub) {
            // x87: the original stores f() as a float (rounded) and divides it by g() unrounded. A float local, not a
            // cast: clang's x87 code leaves `(float)` of an unsigned unrounded in the register
            float n = (float)(unsigned int)sub->f();
            return n / (hulk_freg)(unsigned int)sub->g();
        }
        return 0.0f;
    default:
        return 0.0f;
    }
}