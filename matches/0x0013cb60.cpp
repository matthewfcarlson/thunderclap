class TrackFactoryCasterTemplate_13cb60 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern void* Find(const char*, TrackFactoryCasterTemplate_13cb60*);
void Func(Owner* o, const char* name) {
    TrackFactoryCasterTemplate_13cb60 caster;
    o->Set(Find(name, &caster));
}