extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int gA, gB;
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
namespace hulkfight {
namespace ai {
class TargetDistanceYCondition {};
} // namespace ai
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &gA, &gB, 0) != 0;
}