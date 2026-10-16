class Caster {
  public:
    virtual void Cast();
};
extern int __cdecl Find(int, Caster*);
class Owner {
  public:
    void Apply(int);
};
void __cdecl Target(Owner* owner, int id) {
    Caster caster;
    int v = Find(id, &caster);
    owner->Apply(v);
}