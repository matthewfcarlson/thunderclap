#include "gen/hulkfight.h"

struct C_18f500 {
    void g();
};
struct A_18f500 {
    A_18f500* f1();
    A_18f500* f2();
    char pad[0x128];
    C_18f500* field;
};

void hulkfight::motion::SimulationAction::vfunc_4() {
    A_18f500* a = (*(A_18f500 * *)&this->f_20)->f1();
    A_18f500* b = a->f2();
    if (b->field)
        b->field->g();
}
