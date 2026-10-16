class Caster {
  public:
    virtual void fn();
};
void call(void*, Caster*);
void target(void* p) {
    Caster c;
    call(p, &c);
}