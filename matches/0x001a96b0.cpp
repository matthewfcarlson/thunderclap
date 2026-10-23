class ConditionFactoryCasterTemplate_1a96b0 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Apply(void*);
};
extern "C" void* FUN_002343e0(void*, ConditionFactoryCasterTemplate_1a96b0*);
void Func(Receiver* r, void* p) {
    ConditionFactoryCasterTemplate_1a96b0 c;
    r->Apply(FUN_002343e0(p, &c));
}