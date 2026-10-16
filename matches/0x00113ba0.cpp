struct Caster {
    virtual void Cast();
};
struct Owner {
    void Apply(void*);
};
extern "C" void* __cdecl Find(const char*, Caster*);
void __cdecl Target(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Apply(p);
}