extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
extern int a, b;
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
class UnlockableCondition {};
} // namespace hulkfight
int fight::ConditionFactoryCasterTemplate<hulkfight::UnlockableCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}
