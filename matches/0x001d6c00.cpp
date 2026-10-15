struct Vec {
    float x, y, z;
};
struct View {
    char bytes[64];
    void calc(const float*, Vec*);
};
struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual View* get();
};
struct Owner {
    char pad[0x11c];
    Obj* obj;
    void fn();
};
extern float zero;
void __cdecl output(Vec*);
void Owner::fn() {
    View local = *obj->get();
    Vec v;
    local.calc(&zero, &v);
    output(&v);
}