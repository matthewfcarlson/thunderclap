struct A {
    void* Get();
};
struct B {
    void* Next();
};
struct C {
    void Apply(void*, int, float);
};
class GrappleLocomotionSteerAction {
  public:
    char pad[0x20];
    A* m20;
    void* m24;
    void vfunc_4();
};
void GrappleLocomotionSteerAction::vfunc_4() {
    if (m24) {
        void* a = m20->Get();
        void* b = ((B*)a)->Next();
        if (b)
            ((C*)b)->Apply(m24, 0, -1.0f);
    }
}