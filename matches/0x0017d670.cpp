class Caster {
  public:
    virtual void Cast();
};
void* Find(void*, Caster*);
class Owner {
  public:
    void Apply(void*);
};
void F(Owner* owner, void* key) {
    Caster c;
    void* result = Find(key, &c);
    owner->Apply(result);
}