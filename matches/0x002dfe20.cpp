class Ref_2dfe20 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Base_2dfe20 {
  public:
    Base_2dfe20();
    virtual void f();
    char pad[0x3c];
};
class PrimGroup_2dfe20 : public Base_2dfe20 {
  public:
    int a, b, c, d, e;
    char pad2[4];
    PrimGroup_2dfe20(int x, int y) : Base_2dfe20() {
        a = 0;
        b = 0;
        c = x;
        d = y;
        e = -1;
    }
};
class PrimGroupOptimized : public PrimGroup_2dfe20 {
  public:
    PrimGroupOptimized(Ref_2dfe20*, int, int);
    virtual void f();
    Ref_2dfe20* ref;
    void SetRef(Ref_2dfe20*);
};
inline void PrimGroupOptimized::SetRef(Ref_2dfe20* p) {
    if (p)
        p->AddRef();
    if (ref)
        ref->Release();
    ref = p;
}
PrimGroupOptimized::PrimGroupOptimized(Ref_2dfe20* p, int x, int y) : PrimGroup_2dfe20(x, y) {
    ref = 0;
    SetRef(p);
}
