class ConditionFactoryCasterTemplate_122b70 {
  public:
    virtual void Cast();
};
class Factory {
  public:
    void Add(void*);
};
extern void* Find(const char*, ConditionFactoryCasterTemplate_122b70*);
void Make(Factory* f, const char* name) {
    ConditionFactoryCasterTemplate_122b70 caster;
    f->Add(Find(name, &caster));
}