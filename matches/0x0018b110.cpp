class TrackFactoryCasterTemplate_18b110 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void* Do(void*);
};
extern "C" void* FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b110*);
void* Func(Target* t, void* name) {
    TrackFactoryCasterTemplate_18b110 c;
    void* p = FUN_00236ac0(name, &c);
    return t->Do(p);
}