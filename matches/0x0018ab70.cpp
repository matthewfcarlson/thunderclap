class Caster {
  public:
    virtual void Cast();
};
class Host {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Lookup(void*, Caster*);
void __cdecl Target(Host* host, void* key) {
    Caster caster;
    void* result = Lookup(key, &caster);
    host->Set(result);
}