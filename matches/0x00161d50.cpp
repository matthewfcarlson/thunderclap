struct TrackFactoryCasterTemplate_161d50 {
    virtual void cast();
};
extern "C" void* __cdecl findTrack(void*, TrackFactoryCasterTemplate_161d50*);
class Owner {
  public:
    void add(void*);
};
void function(Owner* owner, void* value) {
    TrackFactoryCasterTemplate_161d50 caster;
    owner->add(findTrack(value, &caster));
}