class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl fun(void*, int, void*, void*, int);
extern int g1, g2;
class Caster_1abdb0 : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int Caster_1abdb0::vfunc_0(void* p) {
    return fun(p, 0, &g1, &g2, 0) != 0;
}