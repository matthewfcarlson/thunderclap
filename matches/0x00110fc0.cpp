namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace ai {
class AIHistoryNameCondition;
}
} // namespace hulkfight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int g1, g2;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}