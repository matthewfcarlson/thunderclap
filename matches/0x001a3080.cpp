extern void* g_vftable_1a3080[];
struct Sub_1a3080 {
    void Fin();
};
class Condition_1a3080 {
  public:
    void* vptr;
    void Fin();
};
class Event_PropStateNameCondition_1a3080 : public Condition_1a3080 {
  public:
    char pad[0xc];
    Sub_1a3080 sub;
    void f();
};
void Event_PropStateNameCondition_1a3080::f() {
    vptr = g_vftable_1a3080;
    sub.Fin();
    Fin();
}
