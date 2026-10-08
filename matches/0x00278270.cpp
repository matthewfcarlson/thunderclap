class Drive { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void* vfunc_4(); char pad[0xc8]; };
class XboxSaveDrive : public Drive { public: void* vfunc_4(); };
void* XboxSaveDrive::vfunc_4() { return (char*)this + 0xcc; }