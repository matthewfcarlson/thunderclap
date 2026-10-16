class Caster {
  public:
    virtual void Cast();
};
extern "C" void* Find(const char*, Caster*);
class Factory {
  public:
    void* Create(void*);
};
void* Target(Factory* factory, const char* name) {
    Caster caster;
    return factory->Create(Find(name, &caster));
}