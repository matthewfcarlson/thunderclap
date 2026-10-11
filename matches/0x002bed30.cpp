extern int vt1, vt2;
extern void Free(void*);
extern void Free2(void*);
class Obj {
  public:
    void Fini();
};
class Ref {
  public:
    virtual void f0();
    virtual void Rel();
};
class Ref2 {
  public:
    virtual void Del(int);
};
class D {
  public:
    void* vptr;
    char p[0x10];
    Ref2* a14;
    Ref* a18;
    Obj* a1c;
    D* vfunc2(unsigned char f);
};
D* D::vfunc2(unsigned char f) {
    Ref* r = a18;
    vptr = &vt1;
    r->Rel();
    if (a14)
        a14->Del(1);
    Obj* o = a1c;
    if (o) {
        o->Fini();
        Free2(o);
    }
    vptr = &vt2;
    if (f & 1)
        Free(this);
    return this;
}
