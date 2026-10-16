extern "C" int __cdecl check(void*, int, void*, void*, int);
extern int a, b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool Test(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TurningVelocityCondition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::TurningVelocityCondition>::Test(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}