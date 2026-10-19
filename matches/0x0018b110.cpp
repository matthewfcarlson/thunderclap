class Caster_18b110 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void* Do(void*);
};
extern "C" void* Find(void*, Caster_18b110*);
void* Func(Target* t, void* name) {
    Caster_18b110 c;
    void* p = Find(name, &c);
    return t->Do(p);
}