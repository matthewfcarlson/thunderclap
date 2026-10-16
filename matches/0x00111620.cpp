extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern void* gA;
extern void* gB;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class FightingOtherNPCCondition {};
} // namespace ai
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_0(void* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}