extern char DAT_00491ca8;
extern char DAT_004b2328;
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
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
namespace motion {
class CollisionTargetSizeCondition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetSizeCondition>::vfunc_0(
    void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004b2328, 0) != 0;
}
