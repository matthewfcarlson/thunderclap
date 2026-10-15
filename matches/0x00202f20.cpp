typedef unsigned char u8;
extern u8 __cdecl query(const char*);
extern const char label[];
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
};
class Method1 : public Base {
  public:
    Method1(void*, void*, void*);
    virtual void f();
    u8 a;
    char gap[7];
    u8 b;
    char gap2[3];
    void* p;
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* q;
};
Method1::Method1(void* x, void* y, void* z) : Base(x, 1) {
    p = z;
    b = query(label);
    a = query(label);
}
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, y, z) {
    q = y;
}
