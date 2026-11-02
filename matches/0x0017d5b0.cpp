class Caster_17d5b0 {
  public:
    virtual void cast();
};
extern void* __cdecl Find(const char*, Caster_17d5b0*);
class Obj {
  public:
    void Process(void*);
};
extern "C" void FUN_0017d5b0(Obj* obj, const char* name) {
    Caster_17d5b0 caster;
    void* p = Find(name, &caster);
    obj->Process(p);
}