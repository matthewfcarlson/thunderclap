extern "C" int __cdecl check(void*, int, void*, void*, int);
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class Event_CharacterTemplateCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* a;
extern void* b;
int ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}