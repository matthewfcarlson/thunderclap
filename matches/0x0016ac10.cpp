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
class HealthPercentCondition {};
} // namespace motion
} // namespace hulkfight
extern int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthPercentCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}