typedef unsigned char u8;
extern u8 __cdecl query(const char*);
extern const char label[];
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
};
class Closure1_202f20 : public Base {
  public:
    Closure1_202f20(void*, void*, void*);
    virtual void f();
    u8 a;
    char gap[7];
    u8 b;
    char gap2[3];
    void* p;
};
class Closure1 : public Closure1_202f20 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* q;
};
Closure1_202f20::Closure1_202f20(void* x, void* y, void* z) : Base(x, 1) {
    p = z;
    b = query(label);
    a = query(label);
}
Closure1::Closure1(void* x, void* y, void* z) : Closure1_202f20(x, y, z) {
    q = y;
}
