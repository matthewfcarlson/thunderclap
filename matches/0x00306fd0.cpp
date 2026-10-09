class Helper { public: void c2(int,int); void c3(void*,void*); };
class CollisionRay {
public:
  virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
  virtual int f4(); virtual void f5(); virtual void f6(); virtual void f7();
  virtual void f8(); virtual void f9(); virtual void f10();
  virtual void f11(Helper* h);
  virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
  virtual void f16(); virtual void f17(); virtual void f18();
  char pad[0x70];
};
void CollisionRay::f11(Helper* h) {
  int a = f4();
  h->c2(f4(), a);
  h->c3((char*)this + 0x74, (char*)this + 0x74);
}
