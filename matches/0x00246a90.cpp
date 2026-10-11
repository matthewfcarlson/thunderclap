extern void* g_vt[];
extern void* g_vt2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
};
class A : public Base {
  public:
    char pad[0x1c - 4];
    Ref* m;
    ~A() throw();
};
A::~A() throw() {
    Ref* r = m;
    vptr = g_vt;
    r->Release();
    vptr = g_vt2;
}
