class Caster_17d180 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* __cdecl find(const char*, Caster_17d180*);
extern "C" void __cdecl FUN_0017d180(Obj* obj, const char* name) {
    Caster_17d180 caster;
    obj->set(find(name, &caster));
}