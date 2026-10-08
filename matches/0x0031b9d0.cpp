class pddiObject { public: virtual void f0(); virtual void f1(); virtual void f2(); };
class pddiDevice : public pddiObject { public: virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); };
namespace pure3d { class d3dDevice : public pddiDevice { public: virtual void vfunc_11(int, int); }; }
void FUN_00327c70(int, int, int);
void pure3d::d3dDevice::vfunc_11(int a, int) { FUN_00327c70(*(int*)((char*)this+0xc), a, 0); }