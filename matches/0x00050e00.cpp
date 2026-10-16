extern int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class CGrappleMotionStateCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight