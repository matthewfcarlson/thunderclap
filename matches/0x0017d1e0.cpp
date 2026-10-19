class Caster_17d1e0 {
  public:
    virtual void f();
};
int first(int, Caster_17d1e0*);
class Obj {
  public:
    void second(int);
};
void target(Obj* obj, int n) {
    Caster_17d1e0 caster;
    int x = first(n, &caster);
    obj->second(x);
}