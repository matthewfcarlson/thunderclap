struct C_18f500 {
    void g();
};
struct A_18f500 {
    A_18f500* f1();
    A_18f500* f2();
    char pad[0x128];
    C_18f500* field;
};
class SimulationAction {
  public:
    char pad[0x20];
    A_18f500* child;
    void vfunc_4();
};
void SimulationAction::vfunc_4() {
    A_18f500* a = child->f1();
    A_18f500* b = a->f2();
    if (b->field)
        b->field->g();
}
