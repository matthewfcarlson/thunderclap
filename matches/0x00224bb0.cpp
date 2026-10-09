typedef unsigned char byte;
extern int g_refCount;
namespace choreo2 {
class JointDriver {
public:
 virtual void a();
 virtual void b();
 virtual JointDriver* vfunc_2(byte);
 virtual void d();
 virtual void e();
 virtual void f();
 virtual void g();
 virtual void h();
 virtual void i();
 virtual void j();
 virtual void k();
 virtual void l();
 virtual void m();
 virtual void n();
};
}
class Helper { public: void call(); };
extern void thunk_FUN_00267090(choreo2::JointDriver*);
choreo2::JointDriver* choreo2::JointDriver::vfunc_2(byte param) {
 *(unsigned long*)this = 0x4272f0;
 --g_refCount;
 ((Helper*)this)->call();
 if (param & 1) thunk_FUN_00267090(this);
 return this;
}
