// Same code shape as 0x00049c80 (propagated; names are from that function)
class CCondition {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
} // namespace fight
class CIsInvincibleCondition : public CCondition, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};
int CIsInvincibleCondition::vfunc_0(int) {
    return 0;
}
