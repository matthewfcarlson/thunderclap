#include "compat/ptr.h"
extern int weaponVftable;
struct SubA_62d70 {
    void init();
};
struct SubB_62d70 {
    void init2();
};
struct CWeaponCollisionTrack_62d70 {
    void finish();
};
class CWeaponCollisionTrack {
  public:
    hulk_intptr vf;
    char x[0x28];
    SubA_62d70 s2c;
    char y[0xb];
    SubA_62d70 s38;
    char z[0xf];
    SubB_62d70 s48;
    CWeaponCollisionTrack* vfunc_5(unsigned char p);
};
void destroy(CWeaponCollisionTrack*);
CWeaponCollisionTrack* CWeaponCollisionTrack::vfunc_5(unsigned char p) {
    vf = (hulk_intptr)&weaponVftable;
    s48.init2();
    s38.init();
    s2c.init();
    ((CWeaponCollisionTrack_62d70*)this)->finish();
    if (p & 1)
        destroy(this);
    return this;
}