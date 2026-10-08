namespace D3D8 { void __stdcall D3DDevice_SetRenderState_MultiSampleAntiAlias(unsigned int); }
class d3dExtAntialiasControl { public: virtual void f0(); virtual void vfunc_1(unsigned char); virtual void f2(); virtual void f3(); virtual void f4(); };
void d3dExtAntialiasControl::vfunc_1(unsigned char value) { D3D8::D3DDevice_SetRenderState_MultiSampleAntiAlias(value); }