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
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern const void* DAT_00491ca8;
extern const void* DAT_00493a30;
bool fight::ConditionFactoryCasterTemplate::vfunc_0(const char* name) {
    return FUN_00344e74(name, 0, &DAT_00491ca8, &DAT_00493a30, 0) != 0;
}