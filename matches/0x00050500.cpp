int __cdecl check(void*, int, void*, void*, int);
extern int g1, g2;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CAxisArcCondition {};
bool fight::ConditionFactoryCasterTemplate<CAxisArcCondition>::vfunc_0(void* p) {
    return check(p, 0, &g1, &g2, 0) != 0;
}
