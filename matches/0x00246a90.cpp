extern void* g_vt_246a90[];
extern void* g_vt2[];
class Ref_246a90 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_246a90 {
  public:
    void* vptr;
};
class A_246a90 : public Base_246a90 {
  public:
    char pad[0x1c - 4];
    Ref_246a90* m;
    ~A_246a90() throw();
};
A_246a90::~A_246a90() throw() {
    Ref_246a90* r = m;
    vptr = g_vt_246a90;
    r->Release();
    vptr = g_vt2;
}
