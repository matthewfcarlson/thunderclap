class Caster {
  public:
    virtual void F();
};
void* __cdecl Find(char*, Caster*);
class Owner {
  public:
    void Use(void*);
};
void __cdecl Target(Owner* owner, char* name) {
    Caster c;
    void* p = Find(name, &c);
    owner->Use(p);
}
