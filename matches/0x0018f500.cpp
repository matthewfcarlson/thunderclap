struct C { void g(); };
struct A { A* f1(); A* f2(); char pad[0x128]; C* field; };
class SimulationAction { public: char pad[0x20]; A* child; void vfunc_4(); };
void SimulationAction::vfunc_4() {
    A* a = child->f1();
    A* b = a->f2();
    if (b->field) b->field->g();
}
