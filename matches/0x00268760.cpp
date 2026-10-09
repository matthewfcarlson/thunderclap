class Target { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(unsigned int); };
class ControllerXBox { char pad[0x454]; Target *member; public: void vfunc_20(unsigned int a, unsigned int b); };
void ControllerXBox::vfunc_20(unsigned int a, unsigned int b) { member->f4(a / b + 2); }