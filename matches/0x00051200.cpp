namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CSmartPropAngleCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
extern int __cdecl lookup(const char*, int, void*, void*, int);
extern void* g1;
extern void* g2;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* name) {
    return lookup(name, 0, &g1, &g2, 0) != 0;
}