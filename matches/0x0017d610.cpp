class Caster_17d610 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(int);
};
extern int __cdecl Find(int, Caster_17d610*);
extern "C" void FUN_0017d610(Obj* obj, int id) {
    Caster_17d610 caster;
    obj->Apply(Find(id, &caster));
}