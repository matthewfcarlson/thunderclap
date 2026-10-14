struct Triple_479e0 {
    int a, b, c;
};
class Obj_479e0 {
  public:
    char pad[0x1ad4];
    int x[6];
    void Set(Triple_479e0* a, Triple_479e0* b);
};
void Obj_479e0::Set(Triple_479e0* a, Triple_479e0* b) {
    x[0] = a->a;
    x[1] = a->b;
    x[2] = a->c;
    x[3] = b->a;
    x[4] = b->b;
    x[5] = b->c;
}