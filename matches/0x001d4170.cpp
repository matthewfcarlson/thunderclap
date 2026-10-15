extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" unsigned char __cdecl FUN_001d04d0(const void*);
extern int g1, g2;
class Parent {
  public:
    Parent(void* x) { FUN_001d0480(x, 1); }
};
class Method : public Parent {
  public:
    virtual void f();
    char p[12];
    unsigned char a;
    char p2[7];
    unsigned char b;
    char p3[3];
    void* obj;
    Method(void* x, void* z) : Parent(x) {
        obj = z;
        b = FUN_001d04d0(&g2);
        a = FUN_001d04d0(&g1);
    }
};
class Closure : public Method {
  public:
    virtual void f();
    void* val;
    Closure(void*, void*, void*);
};
Closure::Closure(void* x, void* y, void* z) : Method(x, z) {
    val = y;
}