class Obj {
  public:
    virtual void A();
    virtual void B();
};
void __stdcall Init(int);
class Thing {
  public:
    char pad[8];
    Obj* p;
    int q;
    Thing* Set(int, Obj*);
};
Thing* Thing::Set(int arg, Obj* value) {
    Init(arg);
    p = 0;
    if (value) {
        value->A();
        if (p)
            p->B();
    }
    p = value;
    q = 0;
    return this;
}