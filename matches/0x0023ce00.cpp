class ConditionFactoryCasterTemplate_23ce00 {
  public:
    virtual void Cast();
};
void* Make(void*, ConditionFactoryCasterTemplate_23ce00*);
class Factory {
  public:
    void Do(void*);
};
void DoIt(Factory* f, void* p) {
    ConditionFactoryCasterTemplate_23ce00 c;
    void* r = Make(p, &c);
    f->Do(r);
}