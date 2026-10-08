class InstanceDrive { public: void *vtable; char pad[8]; void *member; void vfunc_40(); };
class Inner { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); };
void InstanceDrive::vfunc_40() { ((Inner*)member)->f5(); }