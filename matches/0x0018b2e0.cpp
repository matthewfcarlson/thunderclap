class Caster {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, Caster*);
class Target {
  public:
    void* Set(void*);
};
void* __cdecl FUN_0018b2e0(Target* target, void* arg) {
    Caster caster;
    void* p = Find(arg, &caster);
    return target->Set(p);
}