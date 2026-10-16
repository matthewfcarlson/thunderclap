class Base {
  public:
    virtual int check(void*);
    virtual void other();
};
class Caster : public Base {
  public:
    virtual int check(void*);
    virtual void other();
};
extern int fn(void*, int, void*, void*, int);
extern int a, b;
int Caster::check(void* p) {
    return fn(p, 0, &a, &b, 0) != 0;
}