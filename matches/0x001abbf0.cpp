struct TypeInfo {
    int x;
};
extern TypeInfo a, b;
extern "C" void* __cdecl Find(void*, int, TypeInfo*, TypeInfo*, int);
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
    return Find(p, 0, &a, &b, 0) != 0;
}