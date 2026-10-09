class Ref {
  public:
    virtual void F();
};
class Link {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    void Init();
};
class Part {
  public:
    void Init();
};
class Obj : public Base {
  public:
    char pad0[0x1c];
    int mA;
    Link* mLink;
    char pad24[4];
    Part part;
    char pad2c[4];
    int mX;
    int mY;
    char pad38[12];
    int mZ;
    Obj* Func(int a, Ref* r);
};
Obj* Obj::Func(int a, Ref* r) {
    Init();
    *(int*)this = 0x417f64;
    mA = 0;
    mLink = 0;
    part.Init();
    mX = 0;
    mY = 0;
    mZ = 0;
    mA = a;
    if (r)
        r->F();
    if (mLink)
        mLink->B();
    mLink = (Link*)r;
    return this;
}