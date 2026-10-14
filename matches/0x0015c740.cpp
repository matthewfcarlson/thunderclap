struct A_15c740 {
    void* Get();
};
struct B_15c740 {
    void* Next();
};
struct C_15c740 {
    void Apply(void*, int, float);
};
class GrappleLocomotionSteerAction {
  public:
    char pad[0x20];
    A_15c740* m20;
    void* m24;
    void vfunc_4();
};
void GrappleLocomotionSteerAction::vfunc_4() {
    if (m24) {
        void* a = m20->Get();
        void* b = ((B_15c740*)a)->Next();
        if (b)
            ((C_15c740*)b)->Apply(m24, 0, -1.0f);
    }
}