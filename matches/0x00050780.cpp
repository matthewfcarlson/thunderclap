class CButtonReleaseCondition;
extern "C" int __cdecl check(CButtonReleaseCondition*, int, void*, void*, int);
extern void* a;
extern void* b;
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
    return check(p, 0, &a, &b, 0) != 0;
}