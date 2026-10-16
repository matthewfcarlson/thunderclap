extern "C" int __cdecl FUN_00344e74(const char*, const char*, const char*, const char*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class RandomKeyWordWaitCondition {};
} // namespace ai
} // namespace hulkfight
extern const char g1[];
extern const char g2[];
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::ai::RandomKeyWordWaitCondition>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, g1, g2, 0) != 0;
}