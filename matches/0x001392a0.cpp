class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void Do(void*);
};
extern void* __cdecl Cast(void*, Caster*);
void Run(Obj* obj, void* input) {
    Caster caster;
    obj->Do(Cast(input, &caster));
}