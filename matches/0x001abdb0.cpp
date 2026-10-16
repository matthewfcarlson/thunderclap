class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern int __cdecl fun(void*, int, void*, void*, int);
extern int g1, g2;
class Caster : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int Caster::vfunc_0(void* p) {
    return fun(p, 0, &g1, &g2, 0) != 0;
}