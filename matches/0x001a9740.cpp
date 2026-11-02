class ConditionFactoryCasterTemplate_1a9740 {
  public:
    virtual void Cast();
};
extern ConditionFactoryCasterTemplate_1a9740* __cdecl Lookup(void*, ConditionFactoryCasterTemplate_1a9740*);
class Obj {
  public:
    void* Get(ConditionFactoryCasterTemplate_1a9740*);
};
extern "C" void* FUN_001a9740(Obj* o, void* p) {
    ConditionFactoryCasterTemplate_1a9740 c;
    return o->Get(Lookup(p, &c));
}