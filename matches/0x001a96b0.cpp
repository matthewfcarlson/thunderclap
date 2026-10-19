class Caster_1a96b0 {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Apply(void*);
};
extern "C" void* Find(void*, Caster_1a96b0*);
void Func(Receiver* r, void* p) {
    Caster_1a96b0 c;
    r->Apply(Find(p, &c));
}