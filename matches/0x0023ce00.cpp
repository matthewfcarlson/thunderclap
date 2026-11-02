class ConditionFactoryCasterTemplate_23ce00 {
  public:
    virtual void Cast();
};
void* Make(void*, ConditionFactoryCasterTemplate_23ce00*);
class Factory {
  public:
    void Do(void*);
};
extern "C" void FUN_0023ce00(Factory* f, void* p) {
    ConditionFactoryCasterTemplate_23ce00 c;
    void* r = Make(p, &c);
    f->Do(r);
}