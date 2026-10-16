struct CNameFlagCondition {};
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern void* a;
extern void* b;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return helper(p, 0, &a, &b, 0) != 0;
}