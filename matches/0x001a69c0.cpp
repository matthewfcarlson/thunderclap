extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
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
extern void* DAT_00491ca8;
extern void* DAT_004c1e58;
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c1e58, 0) != 0;
}