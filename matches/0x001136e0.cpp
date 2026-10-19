class Caster_1136e0 {
  public:
    virtual void f();
};
void other(void*, Caster_1136e0*);
void target(void* p) {
    Caster_1136e0 c;
    other(p, &c);
}