class TrackFactoryCasterTemplate_1392a0 {
  public:
    virtual void f();
};
class Obj {
  public:
    void Do(void*);
};
extern void* __cdecl Cast(void*, TrackFactoryCasterTemplate_1392a0*);
void Run(Obj* obj, void* input) {
    TrackFactoryCasterTemplate_1392a0 caster;
    obj->Do(Cast(input, &caster));
}