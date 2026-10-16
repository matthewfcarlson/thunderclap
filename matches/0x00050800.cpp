extern "C" int __cdecl castFn(void*, int, void*, void*, int);
extern int gA, gB;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return castFn(p, 0, &gA, &gB, 0) != 0;
}