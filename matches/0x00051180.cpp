extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern int a;
extern int b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class CPropActorStateCondition {};
int fight::ConditionFactoryCasterTemplate<CPropActorStateCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}
