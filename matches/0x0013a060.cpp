extern void* g_vftable_13a060[];
struct Sub_13a060 {
    void Fin();
};
class Condition_13a060 {
  public:
    void* vptr;
    void Fin();
};
class FrameReachedCondition_13a060 : public Condition_13a060 {
  public:
    char pad[0xc];
    Sub_13a060 sub;
    void f();
};
void FrameReachedCondition_13a060::f() {
    vptr = g_vftable_13a060;
    sub.Fin();
    Fin();
}
