class SmartPropIsCargoCondition {};
extern "C" int __cdecl Check(void*, int, const void*, const void*, int);
extern int a, b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*) = 0;
    virtual void vfunc_1() = 0;
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <> int ConditionFactoryCasterTemplate<SmartPropIsCargoCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight