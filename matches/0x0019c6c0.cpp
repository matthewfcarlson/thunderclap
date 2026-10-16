class Caster {
  public:
    virtual void cast();
};
void* __cdecl Find(void*, Caster*);
class Obj {
  public:
    void Do(void*);
};
void target(Obj* a, void* b) {
    Caster c;
    void* p = Find(b, &c);
    a->Do(p);
}