struct Helper { void f(); };
class HUDOverlay { public: virtual HUDOverlay* vfunc_0(unsigned char); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); char pad[0x54]; };
extern int hudvt, ovt;
void thunk_FUN_00267090(HUDOverlay*);
HUDOverlay* HUDOverlay::vfunc_0(unsigned char param_2) {
 Helper* h=(Helper*)((char*)this+0x54);
 *(void**)this=&hudvt;
 h->f();
 *(void**)this=&ovt;
 if (param_2 & 1) thunk_FUN_00267090(this);
 return this;
}