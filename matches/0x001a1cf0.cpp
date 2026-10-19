class Caster_1a1cf0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* __cdecl lookup(const char*, Caster_1a1cf0*);
void __cdecl target(Obj* obj, const char* name) {
    Caster_1a1cf0 caster;
    obj->apply(lookup(name, &caster));
}