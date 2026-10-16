extern "C" int __cdecl Check(void*, int, void*, void*, int);
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
class ChargeCondition {};
} // namespace motion
} // namespace hulkfight
extern char a;
extern char b;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::ChargeCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}