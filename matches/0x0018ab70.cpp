class TrackFactoryCasterTemplate_18ab70 {
  public:
    virtual void Cast();
};
class Host {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Lookup(void*, TrackFactoryCasterTemplate_18ab70*);
void __cdecl Target(Host* host, void* key) {
    TrackFactoryCasterTemplate_18ab70 caster;
    void* result = Lookup(key, &caster);
    host->Set(result);
}