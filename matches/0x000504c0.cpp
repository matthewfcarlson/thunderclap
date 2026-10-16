namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CAlertStatusCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int g1, g2;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &g1, &g2, 0) != 0;
}