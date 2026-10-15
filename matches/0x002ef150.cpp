class A {
  public:
    void f();
    char pad[0x40];
};
class B {
  public:
    void f();
    char pad[0x100];
};
class C {
  public:
    void f();
};
class Obj {
  public:
    void clean();
    char p0[0x70];
    A a;
    B b;
    C c;
};
extern Obj* gObj;
extern "C" void __cdecl freeObj(void*);
void destroyObj() {
    Obj* p = gObj;
    if (p) {
        p->c.f();
        p->b.f();
        p->a.f();
        p->clean();
        freeObj(p);
    }
    gObj = 0;
}