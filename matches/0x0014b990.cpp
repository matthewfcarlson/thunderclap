class Caster_14b990 {
  public:
    virtual void cast();
};
extern "C" void* __cdecl Find(void*, Caster_14b990*);
class Obj {
  public:
    void Set(void*);
};
void Fn(Obj* obj, void* name) {
    Caster_14b990 c;
    obj->Set(Find(name, &c));
}