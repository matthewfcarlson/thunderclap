class Caster_158ad0 {
  public:
    virtual void cast();
};
class Track {};
class Owner {
  public:
    void bind(Track*);
};
Track* __cdecl lookup(void*, Caster_158ad0*);
void __cdecl target(Owner* owner, void* key) {
    Caster_158ad0 caster;
    owner->bind(lookup(key, &caster));
}