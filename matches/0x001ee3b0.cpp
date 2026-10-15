extern char g1[];
extern char g2[];
extern void __stdcall FUN_001d0480(void*, int);
extern unsigned char __cdecl FUN_001d04d0(void*);
class Base {
  public:
    Base(void* x) { FUN_001d0480(x, 1); }
};
class Method1 : public Base {
  public:
    virtual void f();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* p;
    Method1(void*, void*, void*);
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* q;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, y, z) {
    q = y;
}
Method1::Method1(void* x, void* y, void* z) : Base(x) {
    p = z;
    b = FUN_001d04d0(g1);
    a = FUN_001d04d0(g2);
}