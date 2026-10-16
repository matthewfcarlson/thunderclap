class Caster {
  public:
    virtual void dummy();
};
class Owner {
  public:
    void Fn(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl Target(Owner* o, void* key) {
    Caster c;
    void* p = Find(key, &c);
    o->Fn(p);
}