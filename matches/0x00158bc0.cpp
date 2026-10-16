class Caster {
  public:
    virtual void Cast();
};
extern void* Find(void*, Caster*);
class Factory {
  public:
    void Add(void*);
};
void Function(Factory* f, void* name) {
    Caster caster;
    void* obj = Find(name, &caster);
    f->Add(obj);
}
