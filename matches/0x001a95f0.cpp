class Caster {
  public:
    virtual void f();
};
class Desc;
extern Desc* __cdecl lookup(const char*, Caster*);
class Owner {
  public:
    void use(Desc*);
};
void fun(Owner* p, const char* s) {
    Caster c;
    Desc* d = lookup(s, &c);
    p->use(d);
}