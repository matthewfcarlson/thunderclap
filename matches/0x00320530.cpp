class pddiExtFramebufferEffects { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); };
class pddiExtension {};
class d3dExtFramebufferEffects : public pddiExtFramebufferEffects, public pddiExtension { public: char pad[0x7a]; void vfunc_3(unsigned char); };
void d3dExtFramebufferEffects::vfunc_3(unsigned char value) { pad[0x79] = value; }