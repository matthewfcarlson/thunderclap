class Caster {
  public:
    virtual void dummy();
};
class Obj {
  public:
    void apply(void*);
};
void* __cdecl find(void*, Caster*);
void fn(Obj* o, void* p) {
    Caster c;
    o->apply(find(p, &c));
}