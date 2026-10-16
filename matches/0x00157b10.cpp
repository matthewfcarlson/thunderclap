class Caster {
  public:
    Caster() {}
    virtual void cast();
};
extern "C" void __cdecl Use(void*, Caster*);
void __cdecl target(void* p) {
    Caster c;
    Use(p, &c);
}