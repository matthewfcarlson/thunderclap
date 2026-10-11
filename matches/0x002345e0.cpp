extern "C" char DAT_004279ac[];
class Obj {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int);
    virtual void s6();
};
struct Condition {
    unsigned vptr;
    Obj* mRef;
    Condition* vfunc_5(unsigned char flags);
    void reset();
};
void Destroy(Condition*);
Condition* Condition::vfunc_5(unsigned char flags) {
    Obj* p = mRef;
    vptr = ((int)DAT_004279ac);
    if (p)
        p->s5(1);
    mRef = 0;
    reset();
    if (flags & 1)
        Destroy(this);
    return this;
}