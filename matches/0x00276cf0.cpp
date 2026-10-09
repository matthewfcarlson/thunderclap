class InstanceDrive {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual bool f21(); virtual bool f22();
 char pad[8]; class Other *other;
 void vfunc_22();
};
class Other { public: virtual void a(); virtual void b(); virtual void c(); virtual void tick(); };
void FUN_0026d6d0(int);
void InstanceDrive::vfunc_22() { while (!f21()) { other->tick(); FUN_0026d6d0(0); } }