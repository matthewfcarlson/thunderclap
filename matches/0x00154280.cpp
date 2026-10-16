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
class HitPushbackCondition {};
} // namespace motion
} // namespace hulkfight
extern int __cdecl helper(void*, int, void*, void*, int);
extern int a, b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::HitPushbackCondition>::vfunc_0(void* p) {
    return helper(p, 0, &a, &b, 0) != 0;
}