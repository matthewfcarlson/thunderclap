extern "C" int __cdecl Check(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CSmartPropStateCondition {};
extern void* a;
extern void* b;
template <> bool fight::ConditionFactoryCasterTemplate<CSmartPropStateCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}