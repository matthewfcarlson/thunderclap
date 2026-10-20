class Caster_12d2e0 {
  public:
    virtual void f();
};
extern "C" int __cdecl find(void*, Caster_12d2e0*);
class Obj {
  public:
    void apply(int);
};
void run(Obj* o, void* p) {
    Caster_12d2e0 c;
    o->apply(find(p, &c));
}