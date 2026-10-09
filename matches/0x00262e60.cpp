struct Stream {
    void* vptr;
    int arg;
    char pad[20];
    int field;
};
extern "C" Stream* __cdecl FUN_00247530(void*);
char DAT_004e7b08;
struct V {
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
    virtual void run();
};
Stream* __cdecl FUN_00262e60(int param) {
    Stream* p = FUN_00247530(&DAT_004e7b08);
    Stream* result = 0;
    if (p) {
        p->field = 0;
        p->vptr = (void*)0x42adc0;
        p->arg = param;
        result = p;
    }
    ((V*)result)->run();
    return result;
}