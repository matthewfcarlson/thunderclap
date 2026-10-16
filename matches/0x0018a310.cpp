class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* Find(const char*, Caster*);
void Func(Owner* owner, const char* name) {
    Caster c;
    void* p = Find(name, &c);
    owner->Set(p);
}