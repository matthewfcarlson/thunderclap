class Caster {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* find(void*, Caster*);
void fun(Track* t, void* name) {
    Caster caster;
    t->apply(find(name, &caster));
}