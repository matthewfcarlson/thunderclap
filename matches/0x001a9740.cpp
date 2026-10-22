class ConditionFactoryCasterTemplate_1a9740 {
  public:
    virtual void Cast();
};
extern ConditionFactoryCasterTemplate_1a9740* __cdecl Lookup(void*, ConditionFactoryCasterTemplate_1a9740*);
class Obj {
  public:
    void* Get(ConditionFactoryCasterTemplate_1a9740*);
};
void* fn(Obj* o, void* p) {
    ConditionFactoryCasterTemplate_1a9740 c;
    return o->Get(Lookup(p, &c));
}