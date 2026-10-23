extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* DAT_00491ca8;
extern void* DAT_004b6c38;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int Test(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int Test(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class LocomotionMotionStateCondition {};
} // namespace motion
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::LocomotionMotionStateCondition>::Test(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b6c38, 0) != 0;
}