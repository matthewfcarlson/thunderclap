#include "compat/ptr.h"
extern "C" char DAT_00431c90[];
class CollisionObjectLoader {
  public:
    unsigned v;
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned d;
    CollisionObjectLoader();
};
CollisionObjectLoader::CollisionObjectLoader() {
    a = 0;
    b = 0x7010000;
    c = 0;
    d = 0;
    v = ((hulk_intptr)DAT_00431c90);
}