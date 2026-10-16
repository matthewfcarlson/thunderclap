class Caster {
  public:
    virtual void cast();
};
class Track;
class Obj {
  public:
    void apply(Track*);
};
Track* find(void*, Caster*);
void target(Obj* o, void* name) {
    Caster c;
    Track* p = find(name, &c);
    o->apply(p);
}