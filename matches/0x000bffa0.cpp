struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char lookup(const void*);
extern int a, b;
class Base : public CtorV_001d0480 {
  public:
    Base(const char* n) : CtorV_001d0480(n, 1) { }
};
class Method1 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    const char* name;
    Method1(const char*, const char*);
};
class Closure1 : public Method1 {
  public:
    virtual void g();
    void* p;
    Closure1(const char*, void*, const char*);
};
Method1::Method1(const char* n, const char* s) : Base(n) {
    name = s;
    y = lookup(&a);
    x = lookup(&b);
}
Closure1::Closure1(const char* n, void* v, const char* s) : Method1(n, s) {
    p = v;
}