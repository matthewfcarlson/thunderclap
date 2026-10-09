class RandomCondition {
  public:
    virtual void F();
};
class Obj {
  public:
    virtual void A();
    void Use(void*);
};
extern void* Build(void* arg, void* storage);
int vtable;
void Target(void* a, void* b) {
    RandomCondition local;
    *(int*)&local = (int)&vtable;
    void* r = Build(b, &local);
    ((Obj*)a)->Use(r);
}