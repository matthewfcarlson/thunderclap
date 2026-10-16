class ShoreNearCondition;
extern void* a;
extern void* b;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
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
template <> bool ConditionFactoryCasterTemplate<ShoreNearCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
} // namespace fight