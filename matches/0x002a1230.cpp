class AmbientLight { public: virtual void v0(); char pad[0x50]; int field; void Init(); AmbientLight* Build(); };
extern void* AmbientLightVTable;
AmbientLight* AmbientLight::Build() { Init(); *(void**)this = &AmbientLightVTable; field = 0; return this; }