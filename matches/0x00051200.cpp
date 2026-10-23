namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CSmartPropAngleCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
extern int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern void* DAT_00491ca8;
extern void* DAT_00493e80;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* name) {
    return FUN_00344e74(name, 0, &DAT_00491ca8, &DAT_00493e80, 0) != 0;
}