extern int FUN_00344e74(int, int, int, int, int);
class ConditionFactoryCasterTemplate {
  public:
    virtual bool vfunc_0(int);
    virtual void vfunc_1();
};
bool ConditionFactoryCasterTemplate::vfunc_0(int a) {
    return (int)FUN_00344e74(a, 0, 0x491ca8, 0x4a3f00, 0) ? 1 : 0;
}