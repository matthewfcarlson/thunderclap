class Condition {
  public:
    virtual void f();
};
class ConditionFactoryCasterTemplate_16aa10 {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* a;
extern void* b;
class Derived : public ConditionFactoryCasterTemplate_16aa10 {
  public:
    virtual bool vfunc_0(void*);
};
bool Derived::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}