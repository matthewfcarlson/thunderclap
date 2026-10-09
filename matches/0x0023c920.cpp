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
class Helper {
  public:
    void f();
};
class SubConditionGroupCondition : public Condition, public Param {
  public:
    virtual void vfunc_5();
    virtual void vfunc_6();
};
void SubConditionGroupCondition::vfunc_6() {
    ((Helper*)((char*)this + 0xc))->f();
}