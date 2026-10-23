extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_00491ca8, DAT_004c2280;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int Test(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int Test(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_PropStateDescCondition {};
} // namespace scenario
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateDescCondition>::Test(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c2280, 0) != 0;
}
