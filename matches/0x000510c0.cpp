class CMotionHitCondition;
extern int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
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
bool ConditionFactoryCasterTemplate<CMotionHitCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
template class ConditionFactoryCasterTemplate<CMotionHitCondition>;
} // namespace fight