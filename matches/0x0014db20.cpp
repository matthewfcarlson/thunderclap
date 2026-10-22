extern void* g_vftable_14db20[];
struct Sub_14db20 {
    void Fin();
};
class Condition_14db20 {
  public:
    void* vptr;
    void Fin();
};
class CollisionSourceNameCondition_14db20 : public Condition_14db20 {
  public:
    char pad[0xc];
    Sub_14db20 sub;
    void f();
};
void CollisionSourceNameCondition_14db20::f() {
    vptr = g_vftable_14db20;
    sub.Fin();
    Fin();
}
