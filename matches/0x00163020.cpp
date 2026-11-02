class TrackFactoryCasterTemplate_163020 {
  public:
    virtual void cast();
};
class Track {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, TrackFactoryCasterTemplate_163020*);
extern "C" void __cdecl FUN_00163020(Track* t, const char* name) {
    TrackFactoryCasterTemplate_163020 caster;
    t->Set(Find(name, &caster));
}