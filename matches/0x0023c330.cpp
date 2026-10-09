class Branch { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void vfunc_7(); };
class Reference : public Branch { public: char pad[0x24]; void vfunc_7(); };
struct Helper { void f(int, int); };
void Reference::vfunc_7() { ((Helper*)((char*)this + 0x28))->f(0,0); Branch::vfunc_7(); }