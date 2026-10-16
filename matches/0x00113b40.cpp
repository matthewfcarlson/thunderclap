class Caster {
  public:
    virtual void cast();
};
class Factory {
  public:
    void use(void*);
};
extern "C" void* __cdecl lookup(const char*, Caster*);
void __cdecl target(Factory* f, const char* name) {
    Caster c;
    void* p = lookup(name, &c);
    f->use(p);
}