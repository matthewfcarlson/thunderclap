typedef unsigned __int64 U64;
struct Caster {
    virtual void Cast();
};
struct Object {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void Load(Caster*, U64);
};
extern U64 hash(void*);
void work(Object* obj, void* name) {
    U64 h = hash(name);
    Caster caster;
    obj->Load(&caster, h);
}
