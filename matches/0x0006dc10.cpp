// Same code shape as 0x000508c0 (propagated; names are from that function)
extern int __cdecl FUN_00344e74(int, int, int, int, int);
extern int gTypeA_6dc10;
extern int gTypeB;
class ConditionFactoryCasterTemplate {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74((int)p, 0, (int)&gTypeA_6dc10, (int)&gTypeB, 0) != 0;
}