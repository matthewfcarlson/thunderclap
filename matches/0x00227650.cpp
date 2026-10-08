typedef unsigned int u32;
void* __cdecl alloc_obj(unsigned int);
class LocomotionStrafeDriver { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void* vfunc_5(); };
class Helper { public: void a(LocomotionStrafeDriver*); void b(LocomotionStrafeDriver*); };
void* LocomotionStrafeDriver::vfunc_5() {
 void* p = alloc_obj(0x1330);
 if (p) {
  ((Helper*)p)->a(this);
  *(u32*)p = 0x4273c4;
  ((Helper*)p)->b(this);
  return p;
 }
 return 0;
}