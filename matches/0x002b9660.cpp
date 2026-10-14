extern "C" char DAT_0042e764[];
struct BillboardObject;
struct Alloc_2b9660 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    void init(BillboardObject*);
};
struct BillboardObject {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void* vfunc_4();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
void* BillboardObject::vfunc_4() {
    Alloc_2b9660* p = (Alloc_2b9660*)thunk_FUN_0008d690(0x60);
    if (p) {
        p->init(this);
        *(unsigned long*)p = ((int)DAT_0042e764);
        *(unsigned long*)((char*)p + 0x58) = 0x3f800000;
        return p;
    }
    return 0;
}