class CivilianTargetCondition;
extern int __cdecl castfn(void*, int, void*, void*, int);
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
extern void *a, *b;
template <> bool fight::ConditionFactoryCasterTemplate<CivilianTargetCondition>::vfunc_0(void* p) {
    return castfn(p, 0, &a, &b, 0) != 0;
}