class Caster {
  public:
    virtual void Cast();
};
class Track {};
Track* Find(const char*, Caster*);
class Owner {
  public:
    Track* Add(Track*);
};
Track* Fun(Owner* owner, const char* name) {
    Caster caster;
    Track* p = Find(name, &caster);
    return owner->Add(p);
}