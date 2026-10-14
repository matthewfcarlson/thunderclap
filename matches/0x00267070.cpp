extern "C" char DAT_00527f40[];
struct Obj_267070 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h(int);
};
struct Handle_267070 {
    Obj_267070* p;
};
extern Handle_267070* __cdecl Get(void*, int);
void __cdecl Target(int x) {
    Handle_267070* h = Get((void*)((int)DAT_00527f40), x);
    h->p->h(x);
}