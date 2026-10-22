struct DynamicCaster_286780 {
    virtual void cast();
};
struct Manager {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int find(DynamicCaster_286780*, __int64);
};
extern __int64 __cdecl hash(const char*);
int load(Manager* manager, const char* name) {
    __int64 h = hash(name);
    DynamicCaster_286780 caster;
    return manager->find(&caster, h);
}