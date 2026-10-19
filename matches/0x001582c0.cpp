class Caster_1582c0 {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* find(void*, Caster_1582c0*);
void fun(Track* t, void* name) {
    Caster_1582c0 caster;
    t->apply(find(name, &caster));
}