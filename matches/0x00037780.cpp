class Ref_37780 {
  public:
    virtual void A();
    virtual void B();
};
struct V3_37780 {
    int x, y, z;
    void Set(const V3_37780* o) {
        x = o->x;
        y = o->y;
        z = o->z;
    }
};
struct Ptr_37780 {
    Ref_37780* r;
    void Set(Ref_37780* n) {
        if (n)
            n->A();
        if (r)
            r->B();
        r = n;
    }
};
class Obj_37780 {
  public:
    Ptr_37780 a;
    Ptr_37780 b;
    int x;
    V3_37780 p;
    V3_37780 q;
    int z;
    void Set(Ref_37780*, Ref_37780*, int, V3_37780*, V3_37780*, int);
};
void Obj_37780::Set(Ref_37780* na, Ref_37780* nb, int nx, V3_37780* np, V3_37780* nq, int nz) {
    a.Set(na);
    b.Set(nb);
    x = nx;
    p.Set(np);
    q.Set(nq);
    z = nz;
}
