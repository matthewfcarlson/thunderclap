class CollisionChargeCondition;
extern "C" int __cdecl Check(void*, int, void*, void*, int);
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
extern void* gA;
extern void* gB;
template <> int fight::ConditionFactoryCasterTemplate<CollisionChargeCondition>::vfunc_0(void* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}