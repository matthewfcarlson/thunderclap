class Track {};
class TrackFactoryCasterTemplate_1424e0 {
  public:
    virtual Track* Cast(void*);
    TrackFactoryCasterTemplate_1424e0() {}
};
Track* __cdecl Find(const char*, TrackFactoryCasterTemplate_1424e0*);
class Owner {
  public:
    void Set(Track*);
};
void __cdecl target(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1424e0 c;
    Track* t = Find(name, &c);
    owner->Set(t);
}
