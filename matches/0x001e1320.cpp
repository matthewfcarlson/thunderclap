extern "C" unsigned char __cdecl query(const void*);
extern const char g1;
extern const char g2;
class Base {
  public:
    virtual void fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    Base(void*, int);
};
class Method : public Base {
  public:
    virtual void fn();
    Method(void* p, int v) : Base(p, 1) {
        x = v;
        b = query(&g1);
        a = query(&g2);
    }
};
class Derived : public Method {
  public:
    virtual void fn();
    int y;
    Derived(void*, int, int);
};
Derived::Derived(void* p, int v, int w) : Method(p, w) {
    y = v;
}