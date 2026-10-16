class Caster {
  public:
    virtual void f();
};
extern "C" int __cdecl find(void*, Caster*);
class Obj {
  public:
    void apply(int);
};
void run(Obj* o, void* p) {
    Caster c;
    o->apply(find(p, &c));
}