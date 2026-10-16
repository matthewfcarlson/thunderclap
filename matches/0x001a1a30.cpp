extern int __cdecl Check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
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
namespace scenario {
class LuaCondition {};
} // namespace scenario
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::LuaCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}