class Caster_1a9740 {
  public:
    virtual void Cast();
};
extern Caster_1a9740* __cdecl Lookup(void*, Caster_1a9740*);
class Obj {
  public:
    void* Get(Caster_1a9740*);
};
void* fn(Obj* o, void* p) {
    Caster_1a9740 c;
    return o->Get(Lookup(p, &c));
}