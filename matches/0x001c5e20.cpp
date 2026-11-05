#include "compat/ptr.h"
class Obj_1c5e20 {
  public:
    void Fn(hulk_intptr a);
    char pad[16];
    struct Sub_1c5e20* m;
};

struct Sub_1c5e20 {
    void Helper(int a);
};

void Obj_1c5e20::Fn(hulk_intptr a) {
    if (m)
        m->Helper(a);
}
