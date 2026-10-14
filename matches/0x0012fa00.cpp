typedef unsigned int u32_12fa00;
class Result_12fa00 {
  public:
    void run();
};
class Helper_12fa00 {
  public:
    Result_12fa00* run(u32_12fa00);
};
extern Helper_12fa00* gGlobal_12fa00;
class ActionBase_12fa00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
};
class StatBeginTrialAction : public ActionBase_12fa00 {
  public:
    char pad18[0x18];
    u32_12fa00 m1c;
    u32_12fa00 m20;
    bool vfunc_3(void*, void*);
};
bool StatBeginTrialAction::vfunc_3(void*, void*) {
    if (!m20)
        return false;
    u32_12fa00 x = *(u32_12fa00*)(m1c + 0x10);
    Result_12fa00* q = gGlobal_12fa00->run(x);
    q->run();
    return true;
}