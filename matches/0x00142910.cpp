class ConditionFactoryCasterTemplate_142910 {
  public:
    virtual void Cast();
};
struct Result;
Result* find(const char*, ConditionFactoryCasterTemplate_142910*);
class Manager {
  public:
    void Add(Result*);
};
void func(Manager* mgr) {
    ConditionFactoryCasterTemplate_142910 c;
    mgr->Add(find("wallVelocity", &c));
}