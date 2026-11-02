class ConditionFactoryCasterTemplate_23d250 {
  public:
    virtual void Cast();
};
class Handler {
  public:
    void Set(void*);
};
extern "C" void* __cdecl FUN_002343e0(void*, ConditionFactoryCasterTemplate_23d250*);
extern "C" void __cdecl FUN_0023d250(Handler* h, void* p) {
    ConditionFactoryCasterTemplate_23d250 caster;
    void* v = FUN_002343e0(p, &caster);
    h->Set(v);
}