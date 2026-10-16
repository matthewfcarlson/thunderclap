extern int __cdecl Check(void*, void*, void*, void*, void*);
extern int a, b;
class ConditionFactoryCasterTemplate {
  public:
    virtual bool vfunc_0(void* p);
    virtual void vfunc_1();
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}