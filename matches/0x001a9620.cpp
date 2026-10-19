class Caster_1a9620 {
  public:
    virtual void F();
};
void* __cdecl Find(char*, Caster_1a9620*);
class Owner {
  public:
    void Use(void*);
};
void __cdecl Target(Owner* owner, char* name) {
    Caster_1a9620 c;
    void* p = Find(name, &c);
    owner->Use(p);
}
