class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* __cdecl find(void*, Caster*);
void func(Obj* obj, void* arg) {
    Caster c;
    obj->apply(find(arg, &c));
}