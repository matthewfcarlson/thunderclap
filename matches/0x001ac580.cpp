class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Apply(void*);
};
void* __cdecl Resolve(const char*, Caster*);
void __cdecl FUN_001ac580(Target* obj, const char* name) {
    Caster caster;
    obj->Apply(Resolve(name, &caster));
}