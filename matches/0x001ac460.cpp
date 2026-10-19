class Caster_1ac460 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* __cdecl lookup(const char*, Caster_1ac460*);
void __cdecl target(Obj* obj, const char* name) {
    Caster_1ac460 caster;
    obj->set(lookup(name, &caster));
}