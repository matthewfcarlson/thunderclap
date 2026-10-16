class Caster {
  public:
    virtual void f();
};
extern "C" void* __cdecl findTrack(const char*, Caster*);
class Owner {
  public:
    void set(void*);
};
void __cdecl FUN_0014b540(Owner* o, const char* name) {
    Caster c;
    o->set(findTrack(name, &c));
}
