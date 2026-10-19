class Caster_19c6c0 {
  public:
    virtual void cast();
};
void* __cdecl Find(void*, Caster_19c6c0*);
class Obj {
  public:
    void Do(void*);
};
void target(Obj* a, void* b) {
    Caster_19c6c0 c;
    void* p = Find(b, &c);
    a->Do(p);
}