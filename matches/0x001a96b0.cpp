class Caster {
  public:
    virtual void Cast();
};
class Receiver {
  public:
    void Apply(void*);
};
extern "C" void* Find(void*, Caster*);
void Func(Receiver* r, void* p) {
    Caster c;
    r->Apply(Find(p, &c));
}