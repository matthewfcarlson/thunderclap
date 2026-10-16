extern "C" int __cdecl check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
class CButtonPressCondition {};
template <> int fight::ConditionFactoryCasterTemplate<CButtonPressCondition>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}
