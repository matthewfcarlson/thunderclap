class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Use(int);
};
extern int Find(void*, Caster*);
void target(Obj* obj, void* name) {
    Caster c;
    int x = Find(name, &c);
    obj->Use(x);
}