namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CLuaNumberCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl func(const char*, int, const void*, const void*, int);
extern const void* a;
extern const void* b;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* name) {
    return func(name, 0, &a, &b, 0) != 0;
}