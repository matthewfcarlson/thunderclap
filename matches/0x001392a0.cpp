class Caster_1392a0 {
  public:
    virtual void f();
};
class Obj {
  public:
    void Do(void*);
};
extern void* __cdecl Cast(void*, Caster_1392a0*);
void Run(Obj* obj, void* input) {
    Caster_1392a0 caster;
    obj->Do(Cast(input, &caster));
}