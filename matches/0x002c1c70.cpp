struct Args {
    int a;
    int b;
    int pad;
    int c;
    int d;
    int e;
    int f;
    int g;
    char i;
    char j;
};
struct Object {
    virtual void Run();
};
struct Manager {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    virtual void H();
    virtual void I();
    virtual Object* Create(Args*);
};
extern Manager* gManager;
struct Owner {
    char pad[16];
    Object* value;
    bool Fn(int, int, int, int, int, int, int);
};
bool Owner::Fn(int a, int b, int c, int d, int e, int f, int g) {
    Args x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.d = d;
    x.e = e;
    x.pad = 0;
    x.i = 0;
    x.j = 0;
    x.f = f;
    x.g = g;
    Object* r = gManager->Create(&x);
    value = r;
    if (!r)
        return false;
    r->Run();
    return true;
}
