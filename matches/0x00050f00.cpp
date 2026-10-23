class CInactivityTimerCondition {};
extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
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
extern void* DAT_00491ca8;
extern void* DAT_00493710;
template <> bool fight::ConditionFactoryCasterTemplate<CInactivityTimerCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493710, 0) != 0;
}