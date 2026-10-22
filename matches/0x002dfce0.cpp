class Ref_2dfce0 {
  public:
    virtual void f0();
    virtual void f1();
};
class DrawablePrimitive_2dfce0 {
  public:
    virtual void v();
    DrawablePrimitive_2dfce0(const DrawablePrimitive_2dfce0&);
    char pad[0x3c];
    Ref_2dfce0* ref;
    int a, b, c, d;
};
class PrimGroup : public DrawablePrimitive_2dfce0 {
  public:
    virtual void v();
    PrimGroup(const PrimGroup&);
};
PrimGroup::PrimGroup(const PrimGroup& other) : DrawablePrimitive_2dfce0(other) {
    ref = 0;
    a = other.a;
    b = other.b;
    c = other.c;
    d = other.d;
    Ref_2dfce0* p = other.ref;
    if (p)
        p->f0();
    if (ref)
        ref->f1();
    ref = p;
}
