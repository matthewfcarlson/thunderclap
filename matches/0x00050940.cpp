class CCollisionDirectionCondition;
extern "C" int __cdecl Check(CCollisionDirectionCondition*, int, void*, void*, int);
extern void* a;
extern void* b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CCollisionDirectionCondition*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(CCollisionDirectionCondition*);
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(CCollisionDirectionCondition* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}