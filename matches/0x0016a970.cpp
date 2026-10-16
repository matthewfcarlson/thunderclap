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
class RayCastCondition {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* a;
extern void* b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RayCastCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}