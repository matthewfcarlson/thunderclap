class Data {
  public:
    char pad[0x10];
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j(int, int*);
};
class RenderThing {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int vfunc_3(int);
    virtual void d();
    virtual void e();
    int pad;
    int source;
    struct V {
        int a, b, c;
    } vec;
};
int RenderThing::vfunc_3(int p) {
    V local;
    if (p) {
        local = vec;
        Data* d = *(Data**)((char*)p + 0x10);
        d->j(source, (int*)&local);
    }
    return p;
}