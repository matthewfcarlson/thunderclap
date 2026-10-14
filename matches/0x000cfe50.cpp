extern "C" unsigned char __cdecl FUN_001d04d0(const void*);
extern char a, b, c;
class Base {
  public:
    virtual void f();
    Base(void*, int);
};
class Method2 : public Base {
  public:
    virtual void g();
    char pad[0xc];
    unsigned char x, y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    void* obj;
    Method2(void* p, void* q) : Base(p, 2) {
        obj = q;
        z = FUN_001d04d0(&a);
        x = FUN_001d04d0(&b);
        y = FUN_001d04d0(&c);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void h();
    void* extra;
    Closure2(void* p, void* q, void* r);
};
Closure2::Closure2(void* p, void* q, void* r) : Method2(p, r) {
    extra = q;
}