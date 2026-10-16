class Caster {
  public:
    virtual void f();
};
void other(void*, Caster*);
void target(void* p) {
    Caster c;
    other(p, &c);
}