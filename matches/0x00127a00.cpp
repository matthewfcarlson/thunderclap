extern "C" int __cdecl Check(void*, int, const void*, const void*, int);
extern int a, b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class TargetCaster : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::TargetCaster::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}