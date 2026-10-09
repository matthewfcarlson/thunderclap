struct R { char a[4]; int type; char b[12]; int name; };
extern void* Find(void*, int, void*, void*, int);
struct Obj { R* Get(); };
class C {
public:
  virtual void f0();
  virtual void f1();
  virtual void f2();
  virtual void f3();
  virtual void f4();
  virtual void f5();
  virtual bool f6(void* x, void* y, void* z);
  char pad[8];
  int mode;
  int expected;
};
bool C::f6(void* x, void* y, void* z) {
  void* p = Find(y, 0, (void*)0x494b44, (void*)0x4c13d0, 0);
  if (!p) return false;
  R* q = ((Obj*)p)->Get();
  if (q->type != 15) return false;
  int n = q->name;
  switch (mode) {
  case 0: return n == expected;
  case 1: return n != expected;
  }
  return false;
}
