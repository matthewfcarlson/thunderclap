class ConditionFactoryCasterTemplate_1ac2e0 {
  public:
    virtual void f();
};
int __cdecl FUN_002343e0(int, ConditionFactoryCasterTemplate_1ac2e0*);
class Owner {
  public:
    void Apply(int);
};
extern "C" void FUN_001ac2e0(Owner* owner, int id) {
    ConditionFactoryCasterTemplate_1ac2e0 c;
    owner->Apply(FUN_002343e0(id, &c));
}