class Caster_122ab0 {
  public:
    virtual void fn();
};
void call(void*, Caster_122ab0*);
void target(void* p) {
    Caster_122ab0 c;
    call(p, &c);
}