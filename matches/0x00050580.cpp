class CAxisDoubleTapCondition;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_00491ca8, DAT_00491ea0;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00491ea0, 0) != 0;
}
} // namespace fight