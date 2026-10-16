class Caster {
  public:
    virtual void cast();
};
void __cdecl use(void*, Caster*);
void __cdecl target(void* p) {
    Caster c;
    use(p, &c);
}