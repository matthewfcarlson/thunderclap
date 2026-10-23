namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_FirstTimeCondition {};
} // namespace scenario
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_00491ca8, DAT_004c31b8;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_FirstTimeCondition>::Check(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c31b8, 0) != 0;
}