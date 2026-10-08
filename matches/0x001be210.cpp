class Overlay { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
class CSubtitleOverlay : public Overlay { public: char pad[0x11d - sizeof(void*)]; unsigned char field; virtual void vfunc_2(); };
void CSubtitleOverlay::vfunc_2() { field = 0; }