extern "C" int __cdecl CastQuery(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplateCAxisDirectionCondition : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
extern void* a;
extern void* b;
bool fight::ConditionFactoryCasterTemplateCAxisDirectionCondition::vfunc_0(void* p) {
    return CastQuery(p, 0, &a, &b, 0) != 0;
}