class TrackFactoryCasterTemplate_18a310 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18a310*);
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a310 c;
    void* p = FUN_00236ac0(name, &c);
    owner->Set(p);
}