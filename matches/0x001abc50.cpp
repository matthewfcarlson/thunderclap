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
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern int a, b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_FirstTimeCondition>::Check(void* p) {
    return helper(p, 0, &a, &b, 0) != 0;
}