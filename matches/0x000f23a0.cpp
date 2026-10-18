typedef unsigned __int64 U64;
struct Caster {
    virtual void Cast();
};
struct Object {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Load(Caster*, U64);
};
extern U64 hash(void*);
int work(Object* obj, void* name) {
    U64 h = hash(name);
    Caster caster;
    return obj->Load(&caster, h);
}
