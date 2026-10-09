class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base {
  public:
    virtual ~Base() throw();
    char pad[0x3c];
};
class Comp : public Base {
  public:
    virtual ~Comp() throw();
    void Clear();
    Ref* a;
    Ref* b;
    Ref* c;
    Ref* d;
    Ref* e;
};
Comp::~Comp() throw() {
    Clear();
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    if (e) {
        e->Release();
        e = 0;
    }
}
