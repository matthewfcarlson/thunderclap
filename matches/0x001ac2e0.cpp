class ConditionFactoryCasterTemplate_1ac2e0 {
  public:
    virtual void f();
};
int __cdecl Find(int, ConditionFactoryCasterTemplate_1ac2e0*);
class Owner {
  public:
    void Apply(int);
};
void Run(Owner* owner, int id) {
    ConditionFactoryCasterTemplate_1ac2e0 c;
    owner->Apply(Find(id, &c));
}