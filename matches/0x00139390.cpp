class Caster {
  public:
    virtual void cast();
};
extern "C" int __cdecl first(int, Caster*);
class Obj {
  public:
    void second(int);
};
void func(Obj* o, int n) {
    Caster c;
    int r = first(n, &c);
    o->second(r);
}