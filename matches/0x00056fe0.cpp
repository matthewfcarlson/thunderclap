extern "C" void* __cdecl Allocate(unsigned int);
class CAxisReleaseCondition { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); void Init(); };
class Factory { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); CAxisReleaseCondition* vfunc_5(); };
CAxisReleaseCondition* Factory::vfunc_5() {
 CAxisReleaseCondition* p=(CAxisReleaseCondition*)Allocate(0x18);
 if (p) {
  p->Init();
  *(void**)p=(void*)0x3f9130;
  return p;
 }
 return 0;
}
