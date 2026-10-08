class Overlay { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
class HUDOverlay : public Overlay { char pad[0x50 - 4]; public: virtual void vfunc_1(); };
void HUDOverlay::vfunc_1() { *((char*)this + 0x50) = 1; }