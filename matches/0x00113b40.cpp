class Caster {
  public:
    virtual void cast();
};
class Factory {
  public:
    void use(void*);
};
extern "C" void* __cdecl lookup(const char*, Caster*);
extern "C" void __cdecl FUN_00113b40(Factory* f, const char* name) {
    Caster c;
    void* p = lookup(name, &c);
    f->use(p);
}