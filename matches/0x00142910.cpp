class ConditionFactoryCasterTemplate_142910 {
  public:
    virtual void Cast();
};
struct Result;
extern "C" Result* FUN_002343e0(const char*, ConditionFactoryCasterTemplate_142910*);
class Manager {
  public:
    void Add(Result*);
};
extern "C" void FUN_00142910(Manager* mgr) {
    ConditionFactoryCasterTemplate_142910 c;
    mgr->Add(FUN_002343e0("wallVelocity", &c));
}