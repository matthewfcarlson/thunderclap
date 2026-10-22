class TrackFactoryCasterTemplate_14b510 {
  public:
    virtual void Cast();
};
extern "C" void* Find(const char*, TrackFactoryCasterTemplate_14b510*);
class Factory {
  public:
    void* Create(void*);
};
void* Target(Factory* factory, const char* name) {
    TrackFactoryCasterTemplate_14b510 caster;
    return factory->Create(Find(name, &caster));
}