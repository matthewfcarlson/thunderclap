struct TypeInfo {
    int x;
};
extern TypeInfo a, b;
extern "C" int __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
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
namespace ai {
class ProjectileDistanceCondition {};
} // namespace ai
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::ProjectileDistanceCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}