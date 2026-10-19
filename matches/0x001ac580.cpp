class Caster_1ac580 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Apply(void*);
};
void* __cdecl Resolve(const char*, Caster_1ac580*);
void __cdecl FUN_001ac580(Target* obj, const char* name) {
    Caster_1ac580 caster;
    obj->Apply(Resolve(name, &caster));
}