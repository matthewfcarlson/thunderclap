class Caster {
  public:
    virtual void f();
};
extern void fun(void*, Caster*);
void target(void* p) {
    Caster c;
    fun(p, &c);
}