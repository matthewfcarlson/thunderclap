struct TypeDesc;
extern TypeDesc DAT_00491ca8, DAT_00492f30;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeDesc*, TypeDesc*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* y) {
    return FUN_00344e74(y, 0, &DAT_00491ca8, &DAT_00492f30, 0) != 0;
}
} // namespace fight