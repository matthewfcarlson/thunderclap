class RandomCondition {
  public:
    virtual void F();
};
class Obj_2386e0 {
  public:
    virtual void A();
    void Use(void*);
};
extern void* Build(void* arg, void* storage);
extern "C" char DAT_0042827c[];
void Target(void* a, void* b) {
    RandomCondition local;
    *(int*)&local = (int)DAT_0042827c;
    void* r = Build(b, &local);
    ((Obj_2386e0*)a)->Use(r);
}