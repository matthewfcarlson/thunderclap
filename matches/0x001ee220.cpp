extern "C" unsigned char __cdecl lookup(const void*);
extern int g1, g2;
class Base {
  public:
    Base(void*, int);
    virtual void invoke();
    char pad[12];
    unsigned char b;
    char pad2[7];
    unsigned char a;
    char pad3[3];
    void* obj;
};
class Method1 : public Base {
  public:
    Method1(void* x, void* z) : Base(x, 1) {
        obj = z;
        a = lookup(&g1);
        b = lookup(&g2);
    }
    virtual void invoke();
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void invoke();
    void* fn;
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    fn = y;
}