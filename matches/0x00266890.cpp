extern int FUN_00267f80();
struct Obj {
    virtual void V();
};
struct Data {
    char c;
    char pad[0xff];
    int a, b, d;
    char e;
    char pad2[3];
};
class Base {
  public:
    virtual void W();
    Base() { a1 = 0; }
    int a1;
};
void Base::W() {}
class LoadRequest : public Base {
  public:
    virtual void W();
    LoadRequest(const Data*);
    int a2;
    int a3, a4, a5, a6, a7;
    Data d;
};
void LoadRequest::W() {}
LoadRequest::LoadRequest(const Data* src) {
    Data* p = &d;
    p->c = 0;
    p->a = 0;
    p->b = 0;
    p->d = 0;
    p->e = 0;
    *p = *src;
    a2 = FUN_00267f80();
    a3 = 0;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
    Obj* o = (Obj*)d.b;
    if (o)
        o->V();
}