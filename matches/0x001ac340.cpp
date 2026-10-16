class Caster {
  public:
    virtual void cast();
};
class Factory {
  public:
    void apply(void*);
};
void* __cdecl find(void*, Caster*);
void __cdecl target(Factory* f, void* name) {
    Caster caster;
    f->apply(find(name, &caster));
}