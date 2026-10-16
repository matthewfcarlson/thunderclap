namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetDirectionCondition {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* a;
extern void* b;
class Caster : public fight::ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void* p);
    virtual void vfunc_1();
};
bool Caster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}