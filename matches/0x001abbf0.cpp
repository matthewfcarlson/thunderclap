struct TypeInfo {
    int x;
};
extern TypeInfo DAT_00491ca8, DAT_004c30f8;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
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
class EventCondition {};
} // namespace scenario
} // namespace hulkfight
template <> int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::EventCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c30f8, 0) != 0;
}