extern int gA;
extern int gB;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class LeashedConditionCaster : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool LeashedConditionCaster::vfunc_0(void* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fight