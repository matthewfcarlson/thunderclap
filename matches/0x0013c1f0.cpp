class Caster_13c1f0 {
  public:
    virtual void cast();
};
void __cdecl use(void*, Caster_13c1f0*);
void __cdecl target(void* p) {
    Caster_13c1f0 c;
    use(p, &c);
}