class TrackFactoryCasterTemplate_18a0a0 {
  public:
    virtual void* Cast(void*);
};
class Owner {
  public:
    void* Add(void*);
};
extern "C" void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18a0a0*);
extern "C" void* __cdecl FUN_0018a0a0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a0a0 c;
    return owner->Add(FUN_00236ac0(name, &c));
}