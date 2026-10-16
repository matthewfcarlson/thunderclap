namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
};
} // namespace fight
namespace hulkfight {
class MissionProgressCondition {};
} // namespace hulkfight
extern "C" int __cdecl helper(const char*, int, const void*, const void*, int);
extern void* a;
extern void* b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::MissionProgressCondition>::vfunc_0(const char* s) {
    return helper(s, 0, &a, &b, 0) != 0;
}