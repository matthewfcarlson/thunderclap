class Obj { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(void*); };
class Owner { public: char pad[0x14]; Obj* a; void* b; void run(); };
void Owner::run() { if (a && b) a->f10(b); }