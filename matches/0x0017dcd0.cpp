class Caster {
  public:
    virtual void cast();
};
struct Owner {
    void add(void*);
};
extern "C" void* __cdecl find(int, Caster*);
void __cdecl target(Owner* owner, int id) {
    Caster caster;
    owner->add(find(id, &caster));
}