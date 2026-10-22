class Track;
class TrackFactoryCasterTemplate_1325f0 {
  public:
    virtual Track* Cast(void*);
};
extern "C" void* Find(const char*, TrackFactoryCasterTemplate_1325f0*);
class Owner {
  public:
    void Set(void*);
};
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1325f0 c;
    owner->Set(Find(name, &c));
}