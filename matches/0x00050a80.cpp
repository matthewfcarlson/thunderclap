extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* DAT_00491ca8;
extern void* DAT_00492b28;
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
class CCollisionPushbackDirectionCondition {};
template <>
int fight::ConditionFactoryCasterTemplate<CCollisionPushbackDirectionCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00492b28, 0) != 0;
}
