class Caster {
  public:
    virtual void f();
};
class Target {
  public:
    void Run(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void Func(Target* target, void* name) {
    Caster caster;
    void* p = Find(name, &caster);
    target->Run(p);
}