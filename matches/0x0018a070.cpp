class TrackFactoryCasterTemplate_18a070 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Attach(void*);
};
extern "C" void* __cdecl Find(const char*, TrackFactoryCasterTemplate_18a070*);
extern "C" void FUN_0018a070(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a070 c;
    owner->Attach(Find(name, &c));
}