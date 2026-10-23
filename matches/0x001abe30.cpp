struct Info {
    int DAT_00491ca8;
};
extern Info DAT_00491ca8, DAT_004c3508;
extern int __cdecl FUN_00344e74(void*, int, Info*, Info*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int test(void*);
    virtual void other();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int test(void*);
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_PathNameCondition {};
} // namespace scenario
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PathNameCondition>::test(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c3508, 0) != 0;
}