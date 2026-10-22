class TrackFactoryCasterTemplate_129fb0 {
  public:
    virtual void f();
};
class Target {
  public:
    void Run(void*);
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_129fb0*);
void Func(Target* target, void* name) {
    TrackFactoryCasterTemplate_129fb0 caster;
    void* p = Find(name, &caster);
    target->Run(p);
}