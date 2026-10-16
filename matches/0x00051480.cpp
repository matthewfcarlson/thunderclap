extern "C" int __cdecl Find(int, int, const void*, const void*, int);
extern int a, b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
class CStageCondition;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
int ConditionFactoryCasterTemplate::vfunc_0(int x) {
    return Find(x, 0, &a, &b, 0) != 0;
}
} // namespace fight