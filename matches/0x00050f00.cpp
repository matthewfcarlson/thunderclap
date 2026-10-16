class CInactivityTimerCondition {};
extern "C" int __cdecl check(void*, void*, void*, void*, void*);
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
extern void* a;
extern void* b;
template <> bool fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}