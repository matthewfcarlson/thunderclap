class Caster {
  public:
    virtual void Cast();
};
class Factory {
  public:
    void Add(void*);
};
extern void* Find(const char*, Caster*);
void Make(Factory* f, const char* name) {
    Caster caster;
    f->Add(Find(name, &caster));
}