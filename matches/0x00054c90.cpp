class Caster {
  public:
    virtual void cast();
};
void __cdecl fun(void*, Caster*);
void target(void* p) {
    Caster c;
    fun(p, &c);
}