class TrackFactoryCasterTemplate_129f80 {
  public:
    virtual void Cast();
};
class Track {
  public:
    void Add(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_129f80*);
void Do(Track* track, const char* name) {
    TrackFactoryCasterTemplate_129f80 caster;
    track->Add(FUN_00236ac0(name, &caster));
}