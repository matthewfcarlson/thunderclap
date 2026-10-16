extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern char srcType;
extern char dstType;
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
class PropGrabbableIsMissileCondition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_0(
    void* p) {
    return __RTDynamicCast(p, 0, &srcType, &dstType, 0) != 0;
}