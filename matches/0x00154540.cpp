extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
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
class CollisionSourceNodeCondition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionSourceNodeCondition>::vfunc_0(
    void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}