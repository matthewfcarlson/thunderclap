class Caster {
  public:
    virtual void* Cast(void*);
};
class Track;
class Owner {
  public:
    void Attach(Track*);
};
Track* Find(const char*, Caster*);
void FUN_0017d1b0(Owner* owner, const char* name) {
    Caster caster;
    Track* t = Find(name, &caster);
    owner->Attach(t);
}