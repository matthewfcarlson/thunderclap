extern "C" int FUN_00344e74(int, int, void*, void*, int);
class ConditionFactoryCaster {
  public:
    virtual void f0();
    virtual void f1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(int);
};
bool ConditionFactoryCasterTemplate::vfunc_0(int a) {
    return FUN_00344e74(a, 0, (void*)0x491ca8, (void*)0x4a5570, 0) != 0;
}
