extern int __cdecl check(void*, int, void*, void*, int);
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
namespace hulkfight {
namespace scenario {
class NodeIsNotRunningCondition {};
} // namespace scenario
} // namespace hulkfight
extern void* a;
extern void* b;
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}