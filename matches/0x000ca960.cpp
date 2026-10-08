class Overlay { char pad[0x50]; };
class HUDOverlay : public Overlay { public: virtual void v0(); virtual void v1(); virtual void vfunc_2(); virtual void v3(); virtual void v4(); virtual void v5(); };
void HUDOverlay::vfunc_2() { *((char*)this + 0x50) = 0; }