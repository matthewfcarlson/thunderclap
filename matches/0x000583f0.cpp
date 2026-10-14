extern "C" char DAT_003f7550[];
void* operator new(unsigned int);
class CMotionClimbAngleCondition {
  public:
    void Init(int);
    int w[6];
};
class Factory_583f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    CMotionClimbAngleCondition* vfunc_5();
};
CMotionClimbAngleCondition* Factory_583f0::vfunc_5() {
    CMotionClimbAngleCondition* p = (CMotionClimbAngleCondition*)operator new(0x18);
    if (p) {
        p->Init(0);
        p->w[0] = ((int)DAT_003f7550);
        p->w[3] = 0;
        p->w[4] = 0x3fc90fdb;
        p->w[5] = 0;
        return p;
    }
    return 0;
}
