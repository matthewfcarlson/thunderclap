typedef unsigned __int64 U64;
struct DynamicCaster_f23a0 {
    virtual void Cast();
};
struct Object {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Load(DynamicCaster_f23a0*, U64);
};
extern U64 hash(void*);
int work(Object* obj, void* name) {
    U64 h = hash(name);
    DynamicCaster_f23a0 caster;
    return obj->Load(&caster, h);
}
