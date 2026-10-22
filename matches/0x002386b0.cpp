class ConditionFactoryCasterTemplate_2386b0 {
  public:
    virtual void f();
};
class Owner {
  public:
    void apply(void*);
};
void* locate(const char*, ConditionFactoryCasterTemplate_2386b0*);
void function(Owner* owner, const char* name) {
    ConditionFactoryCasterTemplate_2386b0 c;
    void* p = locate(name, &c);
    owner->apply(p);
}