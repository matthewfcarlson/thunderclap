extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
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
    return Check(p, 0, &a, &b, 0) != 0;
}
