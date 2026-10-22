class TrackFactoryCasterTemplate_129f80 {
  public:
    virtual void Cast();
};
class Track {
  public:
    void Add(void*);
};
extern "C" void* Find(const char*, TrackFactoryCasterTemplate_129f80*);
void Do(Track* track, const char* name) {
    TrackFactoryCasterTemplate_129f80 caster;
    track->Add(Find(name, &caster));
}