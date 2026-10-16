class Caster {
  public:
    virtual void Cast();
};
class Factory {
  public:
    void Add(void*);
};
extern "C" void* Find(const char*, Caster*);
void Function(Factory* factory, const char* name) {
    Caster c;
    factory->Add(Find(name, &c));
}