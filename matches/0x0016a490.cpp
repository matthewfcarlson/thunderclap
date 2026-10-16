extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
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
    return Check(p, 0, &a, &b, 0) != 0;
}