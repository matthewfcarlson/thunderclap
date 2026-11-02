class Caster {
  public:
    virtual void dummy();
};
class Owner {
  public:
    void Fn(void*);
};
void* __cdecl Find(void*, Caster*);
extern "C" void __cdecl FUN_00113b10(Owner* o, void* key) {
    Caster c;
    void* p = Find(key, &c);
    o->Fn(p);
}