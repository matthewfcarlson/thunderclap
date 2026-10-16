typedef unsigned int uint;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int gA, gB;
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
namespace hulkfight {
namespace ai {
class TargetAngleYCondition {};
} // namespace ai
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetAngleYCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &gA, &gB, 0) != 0;
}