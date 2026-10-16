class CGrappleTimerCondition;
int __cdecl Check(CGrappleTimerCondition*, int, void*, void*, int);
extern void* a;
extern void* b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CGrappleTimerCondition*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CGrappleTimerCondition*);
};
bool ConditionFactoryCasterTemplate::vfunc_0(CGrappleTimerCondition* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight