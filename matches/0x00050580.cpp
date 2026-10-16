class CAxisDoubleTapCondition;
extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
extern int a, b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return CastCheck(p, 0, &a, &b, 0) != 0;
}
} // namespace fight