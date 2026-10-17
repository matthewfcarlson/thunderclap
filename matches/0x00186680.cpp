extern char DAT_00491ca8;
extern char DAT_004bd288;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
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
int ConditionFactoryCasterTemplate::vfunc_0(void* value) {
    return FUN_00344e74(value, 0, &DAT_00491ca8, &DAT_004bd288, 0) != 0;
}
} // namespace fight
