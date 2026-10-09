class MemoryTwoWayAllocator {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual bool vfunc_9(int*, int*, int*, int*); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
 char pad[12]; int a0; int a1; int a2; int a3; int a4; int a5;
};
bool MemoryTwoWayAllocator::vfunc_9(int *p, int *q, int *r, int *s) {
 if (p) *p = a3 - a2;
 if (q) *q = a3 - a2;
 if (r) *r = a5 + a4;
 if (s) *s = ((a2 - a3) - a0) + a1;
 return true;
}