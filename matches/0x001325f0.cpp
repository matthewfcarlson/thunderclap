class Track;
class Caster {
  public:
    virtual Track* Cast(void*);
};
extern "C" void* Find(const char*, Caster*);
class Owner {
  public:
    void Set(void*);
};
void Func(Owner* owner, const char* name) {
    Caster c;
    owner->Set(Find(name, &c));
}