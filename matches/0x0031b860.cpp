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
struct Result_31b860 {
    void done();
};
struct Maker_31b860 {
    Result_31b860* make(void*, d3dDevice*);
};
extern Maker_31b860* __cdecl FUN_0008d690(int);
void* d3dDevice::vfunc_8(void* p) {
    Maker_31b860* m = FUN_0008d690(0x450);
    Result_31b860* r;
    if (m)
        r = m->make(p, this);
    else
        r = 0;
    r->done();
    return r;
}