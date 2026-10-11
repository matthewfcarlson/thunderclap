extern int vt1, vt2;
extern void Free(void*);
extern void Free2(void*);
class Obj {
  public:
    void Fini();
};
class Ref {
  public:
    virtual void Del(int);
};
class D {
  public:
    void* vptr;
    char p[0x10];
    Obj* a14;
    Ref* a18;
    D* vfunc2(unsigned char f);
};
D* D::vfunc2(unsigned char f) {
    Obj* o = a14;
    vptr = &vt1;
    if (o) {
        o->Fini();
        Free2(o);
    }
    if (a18)
        a18->Del(1);
    vptr = &vt2;
    if (f & 1)
        Free(this);
    return this;
}
