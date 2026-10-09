class MultiController {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual int vfunc_19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
 char pad[0x34]; int result; int flag; int unused; int count; MultiController **items;
};
int MultiController::vfunc_19() {
 if (!flag) {
  for (unsigned int i=0; i<(unsigned int)count; ++i) if (!items[i]->vfunc_19()) return 0;
  return 1;
 }
 return result;
}