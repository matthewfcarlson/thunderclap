extern int __cdecl check(void*, int, const void*, const void*, int);
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
class VelocityAnimatedXZAngleCondition {};
} // namespace motion
} // namespace hulkfight
extern const int a, b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::VelocityAnimatedXZAngleCondition>::vfunc_0(
    void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}