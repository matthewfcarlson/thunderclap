class TrackFactoryCasterTemplate_13d780 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, TrackFactoryCasterTemplate_13d780*);
void __cdecl f(Target* t, const char* name) {
    TrackFactoryCasterTemplate_13d780 caster;
    void* p = Find(name, &caster);
    t->Set(p);
}