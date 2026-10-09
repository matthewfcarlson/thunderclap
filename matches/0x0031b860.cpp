class d3dDevice {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void* vfunc_8(void*);
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};
struct Result {
    void done();
};
struct Maker {
    Result* make(void*, d3dDevice*);
};
extern Maker* __cdecl FUN_0008d690(int);
void* d3dDevice::vfunc_8(void* p) {
    Maker* m = FUN_0008d690(0x450);
    Result* r;
    if (m)
        r = m->make(p, this);
    else
        r = 0;
    r->done();
    return r;
}