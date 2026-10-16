struct CIntentionSpeedCondition;
extern int __cdecl Check(CIntentionSpeedCondition*, int, void*, void*, int);
extern void* gA;
extern void* gB;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(CIntentionSpeedCondition*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(CIntentionSpeedCondition*);
    virtual void vfunc_1();
};
int ConditionFactoryCasterTemplate::vfunc_0(CIntentionSpeedCondition* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fight