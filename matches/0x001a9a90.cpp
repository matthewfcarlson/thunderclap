class Caster {
  public:
    virtual void dummy();
};
extern "C" void* __cdecl lookup(const char*, Caster*);
class Owner {
  public:
    void accept(void*);
};
void __cdecl target(Owner* owner, const char* name) {
    Caster caster;
    owner->accept(lookup(name, &caster));
}
