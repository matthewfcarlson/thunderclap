class Caster {
  public:
    virtual void cast();
};
class LocatorCaster : public Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* find(const char*, Caster*);
void func(Obj* o, const char* s) {
    LocatorCaster c;
    void* p = find(s, &c);
    o->set(p);
}