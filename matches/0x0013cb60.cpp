class Caster_13cb60 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern void* Find(const char*, Caster_13cb60*);
void Func(Owner* o, const char* name) {
    Caster_13cb60 caster;
    o->Set(Find(name, &caster));
}