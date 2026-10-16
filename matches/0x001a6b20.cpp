extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_LocomotionStateNameCondition {};
} // namespace scenario
} // namespace hulkfight
extern void* g1;
extern void* g2;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_0(
    void* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}