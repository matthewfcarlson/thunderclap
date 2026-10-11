extern "C" char DAT_0042d1ec[];
extern "C" char DAT_0042d28c[];
class Child {
  public:
    virtual void Destroy();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual Child* Get();
};
class Obj {
  public:
    int vptr;
    int x[5];
    Child* c;
    Obj* Build(Obj*);
};
class Base {
  public:
    void Init();
};
class Name {
  public:
    void Copy(Name*);
};
Obj* Obj::Build(Obj* src) {
    ((Base*)this)->Init();
    vptr = ((int)DAT_0042d1ec);
    x[3] = src->x[3];
    x[4] = src->x[4];
    ((Name*)((char*)this + 8))->Copy((Name*)((char*)src + 8));
    vptr = ((int)DAT_0042d28c);
    c = 0;
    if (src->c) {
        Child* p = src->c->Get();
        if (p)
            p->Destroy();
        if (c)
            c->Release();
        c = p;
    }
    return this;
}