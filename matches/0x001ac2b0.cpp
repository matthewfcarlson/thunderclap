class ConditionFactoryCasterTemplate_1ac2b0 {
  public:
    virtual void Cast();
};
class Arg {
  public:
    void Do(void*);
};
extern void* Search(void*, ConditionFactoryCasterTemplate_1ac2b0*);
void FUN_001ac2b0(Arg* obj, void* key) {
    ConditionFactoryCasterTemplate_1ac2b0 caster;
    void* result = Search(key, &caster);
    obj->Do(result);
}