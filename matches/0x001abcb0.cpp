extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* a;
extern void* b;
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
class Event_WaypointCondition;
}
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_WaypointCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}