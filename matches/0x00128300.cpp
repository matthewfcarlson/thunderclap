extern "C" int __cdecl test(void*, int, void*, void*, int);
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
class CanSeeTargetCondition;
}
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_0(void* p) {
    return test(p, 0, &gA, &gB, 0) != 0;
}