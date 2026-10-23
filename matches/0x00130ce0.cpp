extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
extern int DAT_00491ca8, DAT_004aa7c0;
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
template <> int fight::ConditionFactoryCasterTemplate<hulkfight::UnlockableCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004aa7c0, 0) != 0;
}
