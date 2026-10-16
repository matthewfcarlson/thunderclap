extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class Caster : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
int fight::Caster::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}