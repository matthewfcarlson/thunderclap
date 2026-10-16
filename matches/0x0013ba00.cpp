namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class FrameCondition {};
} // namespace motion
} // namespace hulkfight
extern int FUN_00344e74(const char*, int, const void*, const void*, int);
extern int g1, g2;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameCondition>::vfunc_0(const char* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}