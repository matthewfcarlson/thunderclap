class Ref {
  public:
    virtual void A();
    virtual void B();
};
struct V3 {
    int x, y, z;
    void Set(const V3* o) {
        x = o->x;
        y = o->y;
        z = o->z;
    }
};
struct Ptr {
    Ref* r;
    void Set(Ref* n) {
        if (n)
            n->A();
        if (r)
            r->B();
        r = n;
    }
};
class Obj {
  public:
    Ptr a;
    Ptr b;
    int x;
    V3 p;
    V3 q;
    int z;
    void Set(Ref*, Ref*, int, V3*, V3*, int);
};
void Obj::Set(Ref* na, Ref* nb, int nx, V3* np, V3* nq, int nz) {
    a.Set(na);
    b.Set(nb);
    x = nx;
    p.Set(np);
    q.Set(nq);
    z = nz;
}
