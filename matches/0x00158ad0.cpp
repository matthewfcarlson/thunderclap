class Caster {
  public:
    virtual void cast();
};
class Track {};
class Owner {
  public:
    void bind(Track*);
};
Track* __cdecl lookup(void*, Caster*);
void __cdecl target(Owner* owner, void* key) {
    Caster caster;
    owner->bind(lookup(key, &caster));
}