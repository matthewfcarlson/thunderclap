class Caster_12d110 {
  public:
    virtual void cast();
};
void* __cdecl lookup(void*, Caster_12d110*);
class Obj {
  public:
    void* finish(void*);
};
void* __cdecl target(Obj* obj, void* name) {
    Caster_12d110 caster;
    void* found = lookup(name, &caster);
    return obj->finish(found);
}