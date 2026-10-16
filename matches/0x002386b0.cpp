class Caster {
  public:
    virtual void f();
};
class Owner {
  public:
    void apply(void*);
};
void* locate(const char*, Caster*);
void function(Owner* owner, const char* name) {
    Caster c;
    void* p = locate(name, &c);
    owner->apply(p);
}