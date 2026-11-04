#include "compat/ptr.h"
class CProjectile {
  public:
    hulk_intptr a;
    int b;
    int c;
    int d;
    unsigned char e;
    int f;
    CProjectile();
};
extern int projectile_vftable;
CProjectile::CProjectile() {
    b = 0;
    this->a = (hulk_intptr)&projectile_vftable;
    c = -1;
    d = 0;
    e = 0;
    f = 0;
}