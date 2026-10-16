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
class InActiveCondition {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern void* a;
extern void* b;
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::InActiveCondition>::vfunc_0(void* p) {
    return helper(p, 0, &a, &b, 0) != 0;
}