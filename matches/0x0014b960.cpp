class TrackFactoryCasterTemplate_14b960 {
  public:
    virtual void Cast();
};
class Track;
Track* FUN_00236ac0(void*, TrackFactoryCasterTemplate_14b960*);
class Factory {
  public:
    void Add(Track*);
};
void Target(Factory* factory, void* name) {
    TrackFactoryCasterTemplate_14b960 caster;
    Track* track = FUN_00236ac0(name, &caster);
    factory->Add(track);
}