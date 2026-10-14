class A_5dc10;
class Arg_5dc10 {
  public:
    A_5dc10* A1();
};
class A_5dc10 {
  public:
    A_5dc10* B();
    void* D(void*, void*);
};
class R_5dc10 {
  public:
    unsigned int E();
};
class Q_5dc10 {
  public:
    int F(void*, void*, unsigned int);
};
class COpportunityBallTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual int vfunc_12(void*);
    virtual void v13();
    char pad[0x14];
    void* m18;
    void* m1c;
};
extern void* __cdecl FUN_0008d690(unsigned int);
int COpportunityBallTrack::vfunc_12(void* arg) {
    A_5dc10* a = ((Arg_5dc10*)arg)->A1();
    a = a->B();
    if (!a)
        return 0;
    void* m = m18;
    void* n = m1c;
    unsigned int r = ((R_5dc10*)a->D(m, n))->E();
    if (r != 0xffff) {
        Q_5dc10* q = (Q_5dc10*)FUN_0008d690(0x5c);
        if (q)
            return q->F(this, arg, r);
    }
    return 0;
}