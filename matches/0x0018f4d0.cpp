#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct Q_18f4d0 {
    void Go();
};
struct Z {
    char pad[0x128];
    Q_18f4d0* field;
};
struct Y_18f4d0 {
    Z* GetZ();
};
struct X_18f4d0 {
};

bool hulkfight::motion::SimulationAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    X_18f4d0* x = (*(X_18f4d0 * *)&this->f_20);
    Y_18f4d0* y = ((Y_18f4d0 *)((owners::Object_592a0 *)x)->FUN_000592a0());
    Z* z = y->GetZ();
    Q_18f4d0* q = z->field;
    if (!q)
        return false;
    q->Go();
    return true;
}
