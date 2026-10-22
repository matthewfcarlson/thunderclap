class TrackFactoryCasterTemplate_14b960 {
  public:
    virtual void Cast();
};
class Track;
Track* Find(void*, TrackFactoryCasterTemplate_14b960*);
class Factory {
  public:
    void Add(Track*);
};
void Target(Factory* factory, void* name) {
    TrackFactoryCasterTemplate_14b960 caster;
    Track* track = Find(name, &caster);
    factory->Add(track);
}