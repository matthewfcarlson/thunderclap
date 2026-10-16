class Caster {
  public:
    virtual void f();
};
void __cdecl use(void*, Caster*);
void __cdecl target(void* p) {
    Caster c;
    use(p, &c);
}