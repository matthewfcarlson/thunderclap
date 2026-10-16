namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    bool vfunc_0(const char*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class PropMissileCountCondition {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int a, b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropMissileCountCondition>::vfunc_0(
    const char* s) {
    return FUN_00344e74(s, 0, &a, &b, 0) != 0;
}