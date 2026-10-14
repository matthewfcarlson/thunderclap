extern int __cdecl FUN_00344e74(int, int, int, int, int);
extern int gTypeA_508c0;
extern int gTypeB;
class ConditionFactoryCasterTemplate {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74((int)p, 0, (int)&gTypeA_508c0, (int)&gTypeB, 0) != 0;
}