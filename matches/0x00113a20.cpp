class Caster {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl find(void*, Caster*);
class Factory {
  public:
    void apply(void*);
};
void __cdecl FUN_00113a20(Factory* f, void* p) {
    Caster caster;
    f->apply(find(p, &caster));
}