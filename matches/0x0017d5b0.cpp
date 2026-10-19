class Caster_17d5b0 {
  public:
    virtual void cast();
};
extern void* __cdecl Find(const char*, Caster_17d5b0*);
class Obj {
  public:
    void Process(void*);
};
void Func(Obj* obj, const char* name) {
    Caster_17d5b0 caster;
    void* p = Find(name, &caster);
    obj->Process(p);
}