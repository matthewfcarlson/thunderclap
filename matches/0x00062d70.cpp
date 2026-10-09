extern int weaponVftable;
struct SubA { void init(); };
struct SubB { void init2(); };
struct Base { void finish(); };
class CWeaponCollisionTrack { public: int vf; char x[0x28]; SubA s2c; char y[0xb]; SubA s38; char z[0xf]; SubB s48; CWeaponCollisionTrack* vfunc_5(unsigned char p); };
void destroy(CWeaponCollisionTrack*);
CWeaponCollisionTrack* CWeaponCollisionTrack::vfunc_5(unsigned char p) {
  vf = (int)&weaponVftable;
  s48.init2();
  s38.init();
  s2c.init();
  ((Base*)this)->finish();
  if (p & 1) destroy(this);
  return this;
}