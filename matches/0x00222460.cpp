class Ref_222460 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_222460 {
  public:
    char pad[0x10];
    Ref_222460* mRef;
    int a;
    int b;
    int c;
    Obj_222460* Copy(Obj_222460* src);
};
Obj_222460* Obj_222460::Copy(Obj_222460* src) {
    Ref_222460* p = src->mRef;
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