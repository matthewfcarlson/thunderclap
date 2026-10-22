class ConditionFactoryCasterTemplate_1a96b0 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Apply(void*);
};
extern "C" void* Find(void*, ConditionFactoryCasterTemplate_1a96b0*);
void Func(Receiver* r, void* p) {
    ConditionFactoryCasterTemplate_1a96b0 c;
    r->Apply(Find(p, &c));
}