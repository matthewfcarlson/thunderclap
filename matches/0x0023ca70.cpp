class ConditionFactoryCasterTemplate_23ca70 {
  public:
    virtual void dummy();
};
extern "C" void* __cdecl Find(void*, ConditionFactoryCasterTemplate_23ca70*);
class Factory {
  public:
    void Do(void*);
};
void Func(Factory* f, void* p) {
    ConditionFactoryCasterTemplate_23ca70 c;
    f->Do(Find(p, &c));
}