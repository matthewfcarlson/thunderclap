class SmartPropIsCargoCondition {};
extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern int DAT_00491ca8, DAT_004bdb20;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <> int ConditionFactoryCasterTemplate<SmartPropIsCargoCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bdb20, 0) != 0;
}
} // namespace fight