extern "C" char DAT_00527f40[];
struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(int);
};
struct Handle {
    Obj* p;
};
extern Handle* __cdecl Get(void*, int);
void __cdecl Target(int x) {
    Handle* h = Get((void*)((int)DAT_00527f40), x);
    h->p->h(x);
}