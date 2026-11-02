class TrackFactoryCasterTemplate_1463a0 {
  public:
    virtual void Cast();
};
struct Target {
    int Get(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_1463a0*);
extern "C" int FUN_001463a0(Target* t, void* x) {
    TrackFactoryCasterTemplate_1463a0 c;
    void* p = FUN_00236ac0(x, &c);
    return t->Get(p);
}