class Caster {
  public:
    virtual void Cast();
};
void* Make(void*, Caster*);
class Factory {
  public:
    void Do(void*);
};
void DoIt(Factory* f, void* p) {
    Caster c;
    void* r = Make(p, &c);
    f->Do(r);
}