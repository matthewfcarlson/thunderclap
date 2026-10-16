struct Info {
    int a;
};
extern Info a, b;
extern int __cdecl check(void*, int, Info*, Info*, int);
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
    return check(p, 0, &a, &b, 0) != 0;
}