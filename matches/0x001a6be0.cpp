extern int DAT_00491ca8, DAT_004c2350;
extern "C" int __cdecl FUN_00344e74(void*, int, int*, int*, int);
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
class Event_PropTypeCondition;
}
} // namespace hulkfight
template <> int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c2350, 0) != 0;
}
