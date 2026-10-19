struct Caster_161d50 {
    virtual void cast();
};
extern "C" void* __cdecl findTrack(void*, Caster_161d50*);
class Owner {
  public:
    void add(void*);
};
void function(Owner* owner, void* value) {
    Caster_161d50 caster;
    owner->add(findTrack(value, &caster));
}