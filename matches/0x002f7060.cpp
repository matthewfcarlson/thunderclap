#include "compat/ptr.h"
extern int vftable_2f7060;
class PhysicsObjectLoader {
  public:
    int vptr;
    int a;
    int b;
    int c;
    int d;
    PhysicsObjectLoader();
};
PhysicsObjectLoader::PhysicsObjectLoader() {
    a = 0;
    b = 0x7011000;
    c = 0;
    d = 0;
    vptr = (hulk_intptr)&vftable_2f7060;
}
