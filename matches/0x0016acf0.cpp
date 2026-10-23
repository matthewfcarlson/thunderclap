extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* DAT_00491ca8;
extern void* DAT_004b7ac8;
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
namespace motion {
class VelocityAnimatedCondition {};
} // namespace motion
} // namespace hulkfight
template <> int fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b7ac8, 0) != 0;
}
