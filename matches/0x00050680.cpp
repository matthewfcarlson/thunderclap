extern int __cdecl FUN_00344e74(int a, int b, int c, int d, int e);
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
int ConditionFactoryCasterTemplate::vfunc_0(int a) {
    return FUN_00344e74(a, 0, 0x491ca8, 0x492108, 0) != 0;
}
