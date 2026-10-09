struct Vector { int x,y,z; };
struct CCameraManager { void f(Vector,unsigned char); };
struct Function { virtual void a(); virtual void b(); };
struct Method2 : Function {
  char pad[0x18];
  void (CCameraManager::*fn)(Vector,unsigned char);
  virtual void f2(int a, Vector* p, int c);
};
void Method2::f2(int a, Vector* p, int c) {
  ((CCameraManager*)a->*fn)(*p, *((unsigned char*)p+12));
}
