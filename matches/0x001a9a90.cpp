class TrackFactoryCasterTemplate_1a9a90 {
  public:
    virtual void dummy();
};
extern "C" void* __cdecl lookup(const char*, TrackFactoryCasterTemplate_1a9a90*);
class Owner {
  public:
    void accept(void*);
};
void __cdecl target(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1a9a90 caster;
    owner->accept(lookup(name, &caster));
}
