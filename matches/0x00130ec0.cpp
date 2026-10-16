struct Token {
    int x;
};
extern Token a, b;
extern "C" int findThing(void*, int, Token*, Token*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
class ChapterMissionCondition {};
} // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition>::vfunc_0(void* p) {
    return findThing(p, 0, &a, &b, 0) != 0;
}
