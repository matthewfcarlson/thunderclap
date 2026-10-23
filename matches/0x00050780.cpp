class CButtonReleaseCondition;
extern "C" int __cdecl FUN_00344e74(CButtonReleaseCondition*, int, void*, void*, int);
extern void* DAT_00491ca8;
extern void* DAT_00492368;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CButtonReleaseCondition*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CButtonReleaseCondition*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(CButtonReleaseCondition* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492368, 0) != 0;
}