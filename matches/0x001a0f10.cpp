extern "C" char DAT_0041b2e8[];
extern void* operator_new(unsigned int);
struct Sub_1a0f10 {
    void Init();
};
struct MPT {
    int vf;
    int a;
    int b;
    int c;
    float z;
    float w;
    Sub_1a0f10 sub;
    void BaseInit();
};
class Factory_1a0f10 {
  public:
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual MPT* Create();
};
MPT* Factory_1a0f10::Create() {
    MPT* p = (MPT*)operator_new(0x24);
    if (p) {
        p->BaseInit();
        p->vf = ((int)DAT_0041b2e8);
        p->c = 0;
        p->z = -1.0f;
        p->w = 6.2831855f;
        p->sub.Init();
        p->b = 1;
        return p;
    }
    return 0;
}
