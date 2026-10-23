struct Token {
    int x;
};
extern Token DAT_00491ca8, DAT_004aaa68;
extern "C" int FUN_00344e74(void*, int, Token*, Token*, int);
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
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004aaa68, 0) != 0;
}
