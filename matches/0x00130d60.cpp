class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class GameStateCondition {};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern void* gA;
extern void* gB;
extern "C" int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
template <> bool ConditionFactoryCasterTemplate<GameStateCondition>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &gA, &gB, 0) != 0;
}