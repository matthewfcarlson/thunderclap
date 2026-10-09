extern const float zero;
struct d3dExtFramebufferEffects { char pad[0x18]; float value; void vfunc_2(); };
void FUN_00322990();
void FUN_003226d0();
void d3dExtFramebufferEffects::vfunc_2() { if (value != zero) FUN_00322990(); else FUN_003226d0(); }
