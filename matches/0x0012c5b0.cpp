class Object {};
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(Object*);
    virtual void vfunc_1();
};
class ThreatCondition {};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(Object*);
    virtual void vfunc_1();
};
extern "C" void* __cdecl DynamicCast(void*, int, void*, void*, int);
extern void* a;
extern void* b;
template <> bool ConditionFactoryCasterTemplate<ThreatCondition>::vfunc_0(Object* p) {
    return DynamicCast(p, 0, &a, &b, 0) != 0;
}