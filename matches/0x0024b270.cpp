class Obj { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); };
class Target { public: char pad[0x78]; unsigned char index; unsigned char count; unsigned char divisor; int Run(); };
int Target::Run() {
  Obj* o = ((Obj**)this)[index * 3];
  if (o) o->f12();
  int v = (int)index + 1;
  int d = (int)divisor;
  int q = v / d;
  index = (unsigned char)(v % d);
  count--;
  return q;
}
