extern int __cdecl Check(void*, int, void*, void*, int);
extern void* gA;
extern void* gB;
namespace fight {
class ConditionFactoryCasterTemplate {
  public:
    virtual bool vfunc_0(void* p);
    virtual void vfunc_1();
};
} // namespace fight
bool fight::ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}