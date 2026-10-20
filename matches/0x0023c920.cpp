class Condition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};
class Param {
  public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
};
class Helper_23c920 {
  public:
    int f(int, int, int);
};
class SubConditionGroupCondition : public Condition, public Param {
  public:
    virtual void vfunc_5();
    virtual int vfunc_6(int, int, int);
};
int SubConditionGroupCondition::vfunc_6(int a0, int a1, int a2) {
    return ((Helper_23c920*)((char*)this + 0xc))->f(a0, a1, a2);
}