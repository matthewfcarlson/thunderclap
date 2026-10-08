class Overlay { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
class MessageOverlay : public Overlay { public: char pad[0x7bc - 4]; char field; void vfunc_2(); };
void MessageOverlay::vfunc_2() { field = 0; }