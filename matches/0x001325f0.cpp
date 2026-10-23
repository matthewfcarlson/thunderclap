class Track;
class TrackFactoryCasterTemplate_1325f0 {
  public:
    virtual Track* Cast(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1325f0*);
class Owner {
  public:
    void Set(void*);
};
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1325f0 c;
    owner->Set(FUN_00236ac0(name, &c));
}