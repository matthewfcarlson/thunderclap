extern int vt1_2c2620, vt2;
extern void Free(void*);
extern void Free2(void*);
class Obj_2c2620 {
  public:
    void Fini();
};
class Ref_2c2620 {
  public:
    virtual void Del(int);
};
class D {
  public:
    void* vptr;
    char p[0x10];
    Obj_2c2620* a14;
    Ref_2c2620* a18;
    D* vfunc2(unsigned char f);
};
D* D::vfunc2(unsigned char f) {
    Obj_2c2620* o = a14;
    vptr = &vt1_2c2620;
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
