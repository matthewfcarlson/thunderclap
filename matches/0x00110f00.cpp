namespace hulkfight {
namespace ai {
class AIFightNodeCondition {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl Cast(void*, int, void*, void*, int);
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
extern void* g1;
extern void* g2;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::AIFightNodeCondition>::vfunc_0(void* p) {
    return Cast(p, 0, &g1, &g2, 0) != 0;
}