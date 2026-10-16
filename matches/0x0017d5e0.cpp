class Caster {
  public:
    virtual void f();
};
class Holder {
  public:
    void Set(void*);
};
void* Find(void*, Caster*);
void Target(Holder* h, void* x) {
    Caster c;
    void* p = Find(x, &c);
    h->Set(p);
}