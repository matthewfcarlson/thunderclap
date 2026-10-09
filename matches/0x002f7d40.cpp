typedef unsigned int u32;
class Ref {
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
    virtual int check(u32);
};
class Wrap {
  public:
    char pad[0x18];
    Ref* obj;
};
class Agent {
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
    Ref* ref;
};
struct Arg {
    char x[8];
    Wrap* first;
    Wrap* second;
    u32 a;
    u32 b;
};
int Agent::v5(void* p, void* secondArg) {
    Arg* q = (Arg*)p;
    int r = 0;
    if (!q->first->obj->check(q->a) && !q->second->obj->check(q->b)) {
        if (!ref)
            r = 1;
    }
    if (ref)
        ref->d(p, secondArg);
    return r;
}