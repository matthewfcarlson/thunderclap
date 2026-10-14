typedef unsigned int u32_2f7d40;
class Ref_2f7d40 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(void*, void*);
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual int check(u32_2f7d40);
};
class Wrap_2f7d40 {
  public:
    char pad[0x18];
    Ref_2f7d40* obj;
};
class Agent_2f7d40 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(void*, void*);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    char pad[4];
    Ref_2f7d40* ref;
};
struct Arg_2f7d40 {
    char x[8];
    Wrap_2f7d40* first;
    Wrap_2f7d40* second;
    u32_2f7d40 a;
    u32_2f7d40 b;
};
int Agent_2f7d40::v5(void* p, void* secondArg) {
    Arg_2f7d40* q = (Arg_2f7d40*)p;
    int r = 0;
    if (!q->first->obj->check(q->a) && !q->second->obj->check(q->b)) {
        if (!ref)
            r = 1;
    }
    if (ref)
        ref->d(p, secondArg);
    return r;
}