class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
  public:
    char pad[0x10];
    Ref* mRef;
    int a;
    int b;
    int c;
    Obj* Copy(Obj* src);
};
Obj* Obj::Copy(Obj* src) {
    Ref* p = src->mRef;
    if (p)
        p->A();
    if (mRef)
        mRef->B();
    mRef = p;
    a = src->a;
    b = src->b;
    c = src->c;
    return this;
}