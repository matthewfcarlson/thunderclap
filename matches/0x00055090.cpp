class Caster {
  public:
    virtual void cast();
};
void __cdecl helper(void*, Caster*);
void __cdecl target(void* p) {
    Caster c;
    helper(p, &c);
}