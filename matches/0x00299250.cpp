class Ref_299250 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_299250 {
  public:
    virtual ~Base_299250() throw();
    char pad[0x3c];
};
class Comp_299250 : public Base_299250 {
  public:
    virtual ~Comp_299250() throw();
    void Clear();
    Ref_299250* a;
    Ref_299250* b;
    Ref_299250* c;
    Ref_299250* d;
    Ref_299250* e;
};
Comp_299250::~Comp_299250() throw() {
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
