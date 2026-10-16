struct Caster {
    virtual void cast();
};
extern "C" void* __cdecl findTrack(void*, Caster*);
class Owner {
  public:
    void add(void*);
};
void function(Owner* owner, void* value) {
    Caster caster;
    owner->add(findTrack(value, &caster));
}