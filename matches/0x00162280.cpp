class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void run(void*);
};
extern "C" void* find(void*, Caster*);
void FUN_00162280(Obj* obj, void* p) {
    Caster c;
    void* v = find(p, &c);
    obj->run(v);
}