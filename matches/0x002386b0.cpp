class ConditionFactoryCasterTemplate_2386b0 {
  public:
    virtual void f();
};
class Owner {
  public:
    void apply(void*);
};
void* locate(const char*, ConditionFactoryCasterTemplate_2386b0*);
extern "C" void FUN_002386b0(Owner* owner, const char* name) {
    ConditionFactoryCasterTemplate_2386b0 c;
    void* p = locate(name, &c);
    owner->apply(p);
}