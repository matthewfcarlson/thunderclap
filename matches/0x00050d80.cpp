namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
class CGrappleFightNodeParentCondition {};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_00491ca8, DAT_00493328;
template <> int fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493328, 0) != 0;
}