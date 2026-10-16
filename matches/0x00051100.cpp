class CMotionStateCondition;
extern "C" int __cdecl helper(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern void* a;
extern void* b;
template <> int fight::ConditionFactoryCasterTemplate<CMotionStateCondition>::vfunc_0(void* p) {
    return helper(p, 0, &a, &b, 0) != 0;
}