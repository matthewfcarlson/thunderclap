namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
extern int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern void* a;
extern void* b;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}