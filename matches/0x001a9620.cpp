class ConditionFactoryCasterTemplate_1a9620 {
  public:
    virtual void F();
};
void* __cdecl Find(char*, ConditionFactoryCasterTemplate_1a9620*);
class Owner {
  public:
    void Use(void*);
};
extern "C" void __cdecl FUN_001a9620(Owner* owner, char* name) {
    ConditionFactoryCasterTemplate_1a9620 c;
    void* p = Find(name, &c);
    owner->Use(p);
}
