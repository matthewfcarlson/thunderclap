class Caster_17d670 {
  public:
    virtual void Cast();
};
void* Find(void*, Caster_17d670*);
class Owner {
  public:
    void Apply(void*);
};
extern "C" void FUN_0017d670(Owner* owner, void* key) {
    Caster_17d670 c;
    void* result = Find(key, &c);
    owner->Apply(result);
}