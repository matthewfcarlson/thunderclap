class Caster {
  public:
    virtual void f();
};
int __cdecl Find(int, Caster*);
class Owner {
  public:
    void Apply(int);
};
void Run(Owner* owner, int id) {
    Caster c;
    owner->Apply(Find(id, &c));
}