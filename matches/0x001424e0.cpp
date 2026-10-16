class Track {};
class Caster {
  public:
    virtual Track* Cast(void*);
    Caster() {}
};
Track* __cdecl Find(const char*, Caster*);
class Owner {
  public:
    void Set(Track*);
};
void __cdecl target(Owner* owner, const char* name) {
    Caster c;
    Track* t = Find(name, &c);
    owner->Set(t);
}
