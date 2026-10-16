class Caster {
  public:
    virtual void f();
};
int first(int, Caster*);
class Obj {
  public:
    void second(int);
};
void target(Obj* obj, int n) {
    Caster caster;
    int x = first(n, &caster);
    obj->second(x);
}