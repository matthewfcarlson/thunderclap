class CCollisionDirectionCondition;
extern "C" int __cdecl FUN_00344e74(CCollisionDirectionCondition*, int, void*, void*, int);
extern void* DAT_00491ca8;
extern void* DAT_004927d8;
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
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004927d8, 0) != 0;
}