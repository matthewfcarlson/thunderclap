extern void* g_vftable_1471c0[];
struct Sub_1471c0 {
    void Fin();
};
class Condition_1471c0 {
  public:
    void* vptr;
    void Fin();
};
class GrappleAttachJointCondition_1471c0 : public Condition_1471c0 {
  public:
    char pad[0xc];
    Sub_1471c0 sub;
    void f();
};
void GrappleAttachJointCondition_1471c0::f() {
    vptr = g_vftable_1471c0;
    sub.Fin();
    Fin();
}
